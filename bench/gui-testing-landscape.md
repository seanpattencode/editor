# GUI Testing Landscape for Desktop Applications

## Summary

Almost nobody does true end-to-end input latency testing for desktop apps on any platform. Chromium and games are the exceptions. Most projects rely on functional testing without measuring actual latency. Windows has the best tooling (NVIDIA/AMD), macOS has deep profiling (Instruments), Linux has the least support.

## Applications by User Count

| Application | Est. Users | Real Latency Testing | Method |
|-------------|------------|---------------------|--------|
| Chrome/Chromium | ~3B | Yes | Hardware light sensors, screenshot APIs |
| Firefox | ~180M | Partial | Internal perf tests only |
| VS Code | ~35M | No | Playwright/CDP functional tests |
| GNOME apps | ~30M | Functional only | Dogtail + AT-SPI |
| KDE apps | ~20M | Partial | Qt AT-SPI |
| Games | varies | Yes | NVIDIA LDAT, AMD FLM, OpenLDAT |

## Testing Approaches

### 1. Hardware-Based (Gold Standard)

**NVIDIA LDAT (Latency Display Analysis Tool)**
- Discrete hardware with luminance sensor
- Measures click-to-photon latency
- Cross-platform, works with all GPUs
- Used for gaming latency validation

**NVIDIA Reflex Analyzer**
- Built into G-SYNC monitors
- Works with compatible mice
- Real-time end-to-end latency measurement
- Accuracy comparable to 10,000 FPS camera

**OpenLDAT (Open Source)**
- DIY hardware + software solution
- Measures total system latency
- Can test any application interactively
- Linux + NVIDIA showed lowest latency in tests

**High-Speed Camera**
- Traditional method: 240fps minimum, 1000fps preferred
- Manual frame counting
- Expensive and time-consuming

### 2. Software-Based

**AMD Frame Latency Meter**
- Windows only
- No hardware required
- Uses DXGI capture
- Works with any GPU (AMD, NVIDIA, Intel)

**Google latency-benchmark**
- Programmatic input events + screenshot APIs
- Designed for web browsers
- Can run automated with JSON output
- Reference: https://github.com/google/latency-benchmark

**Chromium browser_tests**
- Test binary with Chrome compiled in
- Each test runs in fresh browser process
- `interactive_ui_tests` run on bots with real display sessions

### 3. Accessibility-Based (Functional Testing)

**Dogtail (GNOME/GTK)**
- Python framework using AT-SPI
- Works on X11 and Wayland
- Can simulate input and inspect UI state
- No latency measurement, functional only
- Script recorder for test generation

**LDTP (Linux Desktop Testing Project)**
- Also uses ATK/AT-SPI
- More XML-heavy than Dogtail
- Older but mature

**Qt AT-SPI**
- Enables Dogtail/LDTP for KDE/Qt apps
- Requires `QT_LINUX_ACCESSIBILITY_ALWAYS_ON=1`

### 4. Electron/Web App Testing

**Playwright**
- Microsoft's end-to-end framework
- Experimental Electron support via CDP
- Cross-browser (Chromium, Firefox, WebKit)
- Waits for elements before actions (reduces flakiness)

**WebdriverIO**
- Node.js WebDriver implementation
- Electron desktop testing mode
- Plugin ecosystem for reporters/services

**Spectron (Deprecated)**
- Was the standard for Electron testing
- Microsoft discontinued it
- Replaced by Playwright

---

## Windows Platform

### Functional Testing

**WinAppDriver (Paused Development)**
- Microsoft's Selenium-like UI automation
- Supports UWP, WinForms, WPF, Win32
- Uses UI Automation (UIA) accessibility framework
- Development paused as of 2023
- Reference: https://github.com/microsoft/WinAppDriver

**FlaUI**
- .NET library for Windows UI automation
- Built on Microsoft's native UI Automation
- Active development, WinAppDriver alternative
- Can manipulate windows, controls by automation ID

**Pywinauto**
- Python GUI automation for Windows
- Supports Win32 API and MS UI Automation
- Works with WinForms, WPF, Qt, browsers
- Mouse/keyboard simulation

### Latency Measurement (Best Platform Support)

**NVIDIA FrameView + PC Latency Stats**
- Measures input-to-frame-start, frame-start-to-present, present-to-displayed
- Requires Reflex SDK integration for full metrics
- Works with all DLSS 3 titles
- Real-time overlay and logging
- Reference: https://developer.nvidia.com/frameview

**AMD Frame Latency Meter (FLM)**
- Software-only, no hardware needed
- Measures mouse-to-pixel latency
- Works with any GPU (AMD, NVIDIA, Intel)
- Uses DXGI capture on DirectX 11+
- Open source via GPUOpen

**NVIDIA Reflex Analyzer**
- Hardware in G-SYNC monitors
- Compatible mice report click timing
- End-to-end system latency in real-time
- 10,000 FPS camera accuracy

**PresentMon**
- Open source frame timing tool
- Foundation for FrameView
- ETW-based performance capture
- Reference: https://github.com/GameTechDev/PresentMon

---

## macOS Platform

### Functional Testing

**XCUITest (Apple's Framework)**
- Built into Xcode, Swift/Objective-C
- Uses accessibility identifiers for elements
- Test recording via UI
- Integrated with CI (Xcode Cloud)
- iOS and macOS apps only
- Reference: https://developer.apple.com/documentation/xctest

**Accessibility API**
- Core technology enabling UI automation
- Rich semantic data about UI elements
- Same API used by screen readers
- Foundation for all macOS UI testing

**Squish (Commercial)**
- Cross-platform (Qt, macOS native, Java, etc.)
- Record and playback
- BDD support
- Reference: https://www.qt.io/product/quality-assurance/squish

### Latency/Performance Profiling

**Instruments (Apple)**
- Deep system profiling tool
- Multiple trace templates:
  - **Time Profiler**: CPU/main thread analysis
  - **Core Animation**: FPS, offscreen rendering detection
  - **Metal System Trace**: GPU pipeline, frame times
  - **Hangs**: UI responsiveness issues
- Can measure frame times, not click-to-photon
- Reference: https://developer.apple.com/documentation/xcode/instruments

**Metal Counters API**
- Runtime GPU profiling
- Live HUD with frame times
- Memory usage, resolution stats
- Catch frame hitches in development

**XCTest Performance Metrics**
- `measure(metrics:)` for frame rate, latency, render time
- Runs action sequence multiple times
- Reports average, outliers, statistics
- Good for regression detection, not absolute latency

### Limitations

- No equivalent to NVIDIA LDAT/Reflex
- No software tool for click-to-photon measurement
- Hardware testing requires high-speed camera
- Apple doesn't publish system latency specs

---

## Cross-Platform Tools

### Appium

**Status: Desktop Support Limited**
- Originally mobile-focused (iOS, Android)
- Desktop via platform-specific drivers:
  - Windows: WinAppDriver (paused)
  - macOS: XCUITest driver
  - Linux: No official support
- Appium Desktop deprecated (security issues)
- Use Appium Inspector for element inspection
- Reference: https://github.com/appium/appium

### Playwright

- Best cross-platform web/Electron testing
- Chromium, Firefox, WebKit engines
- Works on Windows, macOS, Linux
- No native app support (web only)
- Reference: https://playwright.dev

### Hardware Tools (Universal)

**NVIDIA LDAT**
- Works on Windows, macOS, Linux
- USB device with light sensor
- Click-to-photon measurement
- GPU agnostic

**High-Speed Camera**
- Universal method
- 240fps minimum, 1000fps preferred
- Works with any OS, any app
- Manual analysis required

**OpenLDAT**
- Open source hardware design
- Arduino-based
- Cross-platform software
- Reference: https://github.com/OSRTT/OSLTT

---

## Platform Comparison

| Capability | Windows | macOS | Linux |
|------------|---------|-------|-------|
| Functional UI testing | WinAppDriver, FlaUI | XCUITest | Dogtail, AT-SPI |
| Accessibility API | UI Automation | Accessibility API | AT-SPI |
| Frame time profiling | FrameView, PresentMon | Instruments | Limited |
| Click-to-photon software | AMD FLM | None | None |
| Hardware latency tools | Reflex Analyzer | LDAT only | LDAT only |
| Compositor latency | DWM metrics | None exposed | Wayland: limited |
| Native tool maturity | High | High | Low |

## Why Real Latency Testing Is Rare

1. **Hardware requirement** - Accurate measurement needs light sensors or high-speed cameras
2. **Wayland complexity** - Input injection harder than X11, screenshot APIs restricted
3. **No standard tooling** - Each project rolls their own or skips it
4. **"Fast enough" assumption** - Devs don't measure, assume acceptable
5. **Cost** - LDAT hardware, high-speed cameras, engineering time

## Historical Context

Dan Luu's 2017 study ("Computer latency: 1977-2017") found:
- Modern computers often have HIGHER latency than 1977 Apple II
- Most applications don't know their own latency
- Average human reaction time: 150-250ms
- Sub-100ms feels "instant", >200ms feels sluggish

## Measurement Levels

| Level | What It Measures | Tools |
|-------|------------------|-------|
| Code path | Function execution time | Profilers, manual timing |
| PTY/IPC | Input parsing to output generation | Our `click_folder.py` |
| Compositor | Window damage to display buffer | Wayland protocols |
| End-to-end | Physical input to photons on screen | LDAT, cameras |

Our PTY-based benchmark measures level 2. True end-to-end requires hardware.

## Recommendations for `e` Editor

1. **Current approach is valid** - PTY measurement captures editor responsiveness
2. **Add compositor timing** - If possible, measure Wayland
3. **Hardware validation** - One-time LDAT or camera test to establish baseline
4. **Regression testing** - PTY tests in CI to catch slowdowns

## References

### General
- Chromium Testing: https://www.chromium.org/developers/testing/
- Google latency-benchmark: https://github.com/google/latency-benchmark
- Dan Luu latency study: https://danluu.com/input-lag/
- Dan Luu keyboard latency: https://danluu.com/keyboard-latency/
- Playwright: https://playwright.dev/

### Linux
- Dogtail: https://pypi.org/project/dogtail/
- AT-SPI: https://wiki.gnome.org/Accessibility

### Windows
- WinAppDriver: https://github.com/microsoft/WinAppDriver
- FlaUI: https://github.com/FlaUI/FlaUI
- Pywinauto: https://github.com/pywinauto/pywinauto
- NVIDIA FrameView: https://developer.nvidia.com/frameview
- NVIDIA Reflex SDK: https://developer.nvidia.com/performance-rendering-tools/reflex
- AMD Frame Latency Meter: https://gpuopen.com/frame-latency-meter/
- PresentMon: https://github.com/GameTechDev/PresentMon

### macOS
- XCUITest: https://developer.apple.com/documentation/xctest
- Instruments: https://developer.apple.com/documentation/xcode/instruments
- Metal System Trace: https://developer.apple.com/documentation/metal/performance_tuning
- Core Animation profiling: https://developer.apple.com/library/archive/documentation/DeveloperTools/Conceptual/InstrumentsUserGuide/

### Hardware
- NVIDIA LDAT: https://developer.nvidia.com/nvidia-latency-display-analysis-tool
- OpenLDAT paper: https://sid.onlinelibrary.wiley.com/doi/10.1002/jsid.1104
- OSRTT/OSLTT: https://github.com/OSRTT/OSLTT
