<div id="top"></div>

<br />
<div align="center">
  <a href="https://github.com/Jax-Core/YourFlyouts">
    <img src="https://cdn.discordapp.com/attachments/875630623853793283/985090665123835944/YourFlyoutsColored.png" alt="Logo" width="200" height="200">
  </a>
  <h3 align="center">YourFlyouts</h3>
  <p align="center">
    Customizability-focused flyouts replacement for Windows 10+
    <br />
    <a href="https://www.deviantart.com/jaxoriginals/art/ValliStart-Start-menu-replacement-893506095"><strong>More Info »</strong>
    </a>
    <br />
    <br />
    <a href="https://discord.gg/JmgehPSDD6">Report Bugs & Request Features</a>
  </p>
</div>

<p align="center">
  <img alt="Latest by date" src="https://img.shields.io/github/v/tag/Jax-Core/YourFlyouts?label=Version&style=for-the-badge" />
  <img alt="Release date" src="https://img.shields.io/github/release-date/Jax-Core/YourFlyouts?label=Last%20Core%20Update&style=for-the-badge" />
  <img alt="Discord" src="https://img.shields.io/discord/880445067754610688?label=Discord%20server&style=for-the-badge" />
  <img alt="Github" src="https://img.shields.io/github/license/Jax-Core/YourFlyouts?style=for-the-badge" />
  
</p>
<!-- ABOUT THE PROJECT -->
## About

![YourFlyouts](https://user-images.githubusercontent.com/80020581/173227106-b4287c13-451f-4c31-b7fc-5cc593f89abb.png)

This module provides multiple replacements for the old, built-in, Metro Design based Audio/Media/Brightness flyouts in Windows which are shown while pressing the media or volume keys.
Along with a number of unique designs, it also provides additional customizability towards the behavioral **and** appearance side of things!

This project is heavily inspired by [ModernFlyouts](https://github.com/ModernFlyouts-Community/ModernFlyouts)! YourFlyouts is still multiple steps from being a complete replacement, but it excels in other ways!
> Note: Built-in flyout will not be permanently affected. It will be hidden temporarily while YourFlyouts is running, hence it does not modify any system files.
> You can also use YourFlyouts to disable the flyout completely!

## Features
* Smooth animations, with the avability to reduce & turn off
* Multiple visual styles
* Supports [NowPlaying](https://docs.rainmeter.net/manual/measures/nowplaying/) and [WebNowPlaying](https://github.com/tjhrulz/WebNowPlaying)
* Extra flyouts for toggling CapsLock, NumLock and ScrollLock
* Customizable Hotkeys
* Supports multiple monitors
* Most aspect of the flyout can be customized to your liking, including **timeout**, **colors**, **size** and anything you can think of

<p align="right">
    <b><a href="#top">↥ back to top</a></b>
</p>

<!-- INSTALLATION AND SETUP -->
## Getting Started

### Prerequisites
- **Windows 10** or above
- For older systems, **Powershell v5.1 or newer** is required. Upgrade powershell **[here](https://docs.microsoft.com/en-us/powershell/scripting/windows-powershell/install/installing-windows-powershell?view=powershell-7.2#upgrading-existing-windows-powershell)**!

### Installation 
**By Powershell CLI:**
Run the following command in Powershell (`win + r` -> `powershell.exe` / search)
```
$installSkin="YourFlyouts";Invoke-WebRequest -UseBasicParsing "https://raw.githubusercontent.com/Jax-Core/JaxCore/master/CoreInstaller.ps1" | Invoke-Expression
```
**By legacy [Rainmeter](https://www.rainmeter.net/) .rmskin installer:**
Download and run the `.rmskin` file from the latest release **[here](https://github.com/Jax-Core/YourFlyouts/releases/latest)**.
> Note:  If you find that the JaxCore option is red on the startup pop-up, please press the red button and Core will be installed automatically. Perchance this fails, you can manually install Core by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)
<br />
<br />
