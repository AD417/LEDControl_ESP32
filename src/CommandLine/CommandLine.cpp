#include "CommandLine.hpp"
#include <SimpleCLI.h>

#include "callbacks.hpp"

SimpleCLI commandLine;

Command altCommand = commandLine.addCommand("alt/ernate", altCallback);
Command colorCommand = commandLine.addCommand("c/olor", colorCallback);
Command echoCommand = commandLine.addBoundlessCmd("echo", echoCallback);
Command fillCommand = commandLine.addCommand("fill,on", fillCallback);  
Command pulseCommand = commandLine.addCommand("pulse", pulseCallback);
Command waveCommand = commandLine.addCommand("wave", waveCallback);

void initCommandLine() {

    commandLine.setOnError(errorCallback); // Set error Callback

    // MUST be run before commands can be used!
    altCommand.addPositionalArgument("interval", "500");
    altCommand.addPositionalArgument("width", "5");
    altCommand.addArgument("c,color", "");
    // TRANSITION!

    colorCommand.addPositionalArgument("color");
    // FLASH!
    // TRANSITION!?

    fillCommand.addArgument("c,color", "");
    // TRANSITION!

    pulseCommand.addPositionalArgument("interval", "500");
    pulseCommand.addArgument("c,color", "");
    // TRANSITION!

    waveCommand.addPositionalArgument("interval", "500");
    waveCommand.addPositionalArgument("wavelength", "5.0");
    waveCommand.addArgument("c,color", "");
}