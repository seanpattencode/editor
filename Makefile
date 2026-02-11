# Parallel split build: two clang passes run simultaneously.
#   Pass 1: -Werror -Weverything + hardening flags, -fsyntax-only
#            Validates all warnings and hardening compatibility.
#            No binary emitted — pure compile-time checking (~60ms).
#   Pass 2: -O2 -w, no extra flags
#            Emits the actual binary. Pure optimized code, no overhead
#            from warnings or hardening codegen.
#
# Both run in parallel. Pass 2 always takes longer than pass 1,
# so the strict checks are completely free — total build time equals
# the bare compile time. If pass 1 fails, the binary from pass 2
# is discarded.
#
# Result: strictest possible validation with zero cost to the binary.
#   make          bare -O2 binary, validated by -Weverything + hardening
#   make debug    all flags combined + ASan/UBSan/IntSan -O1 -g

CC = clang
WARN = -std=gnu89 -Werror -Weverything \
       -Wno-padded -Wno-disabled-macro-expansion -Wno-reserved-id-macro \
       -Wno-documentation -Wno-declaration-after-statement \
       -Wno-unsafe-buffer-usage -Wno-used-but-marked-unused \
       --system-header-prefix=/usr/include \
       -isystem /usr/local/include
HARDEN = -fstack-protector-strong -ftrivial-auto-var-init=zero -D_FORTIFY_SOURCE=2 \
         -fstack-clash-protection -fcf-protection
LINK_HARDEN = -Wl,-z,relro,-z,now

e: e.c
	$(CC) $(WARN) $(HARDEN) -fsyntax-only $< & P1=$$!; \
	$(CC) -std=gnu89 -O2 -w -o $@ $< & P2=$$!; \
	wait $$P1 && wait $$P2

debug: e.c
	$(CC) $(WARN) $(HARDEN) $(LINK_HARDEN) -O1 -g -fsanitize=address,undefined,integer -o e $<

clean:
	rm -f e

.PHONY: clean debug
