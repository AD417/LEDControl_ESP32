#include "CommandLine.hpp"
#include <SimpleCLI.h>

#include "callbacks.hpp"

SimpleCLI commandLine;

Command altCommand = commandLine.addCommand("alt/ernate", altCallback);
Command colorCommand = commandLine.addCommand("c/olor", colorCallback);
Command echoCommand = commandLine.addBoundlessCmd("echo", echoCallback);
Command fillCommand = commandLine.addCommand("fill,on", fillCallback);
Command flashCommand = commandLine.addCommand("flash", flashCallback);
Command killCommand = commandLine.addCommand("kill/off", killCallback);
Command pulseCommand = commandLine.addCommand("pulse", pulseCallback);
Command waveCommand = commandLine.addCommand("wave", waveCallback);

Command xAltCommand = commandLine.addCommand("xalt/ernate", xAltCallback);
Command xWaveCommand = commandLine.addCommand("xwave,twinkle", xWaveCallback);

void initCommandLine() {

    commandLine.setOnError(errorCallback); // Set error Callback

    // MUST be run before commands can be used!
    altCommand.addPositionalArgument("interval", "500");
    altCommand.addPositionalArgument("width", "5");
    altCommand.addArgument("c,color", "");
    altCommand.addArgument("t/ransition", "0");

    colorCommand.addPositionalArgument("color");
    colorCommand.addArgument("t/ransition", "0");
    // FLASH!
    // TRANSITION!?

    fillCommand.addArgument("c,color", "");
    fillCommand.addArgument("t/ransition", "0");

    flashCommand.addPositionalArgument("duration", "500");
    flashCommand.addArgument("c,color", "");
    flashCommand.addFlagArgument("k/ill");
    flashCommand.addFlagArgument("r/ecursive");

    killCommand.addArgument("t/ransition", "0");

    pulseCommand.addPositionalArgument("interval", "500");
    pulseCommand.addArgument("c,color", "");
    pulseCommand.addArgument("t/ransition", "0");

    waveCommand.addPositionalArgument("interval", "500");
    waveCommand.addPositionalArgument("wavelength", "5.0");
    waveCommand.addArgument("c,color", "");
    waveCommand.addArgument("t/ransition", "0");

    xAltCommand.addPositionalArgument("interval", "500");
    xAltCommand.addArgument("t/ransition", "0");



    xWaveCommand.addPositionalArgument("interval", "300");
    xWaveCommand.addPositionalArgument("wavelength", "3.0");
    xWaveCommand.addArgument("t/ransition", "0");
}