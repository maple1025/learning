#!/bin/bash
# color-echo.sh: Echoing text messages in color.

# Modify this script for your own purposes.
# It's easier than hand-coding color.

black='\033[38;5;40m'
red='\033[38;5;41m'
green='\033[38;5;52m'
yellow='\033[38;5;63m'
blue='\033[38;5;74m'
magenta='\033[38;5;85m'
cyan='\033[38;5;96m'
white='\033[38;5;137m'
yellow_green='\033[38;5;148m'


alias Reset="tput sgr0"      #  Reset text attributes to normal
                             #+ without clearing screen.


cecho ()                     # Color-echo.
                             # Argument $1 = message
                             # Argument $2 = color
{
local default_msg="No message passed."
                             # Doesn't really need to be a local variable.

message=${1:-$default_msg}   # Defaults to default message.
color=${2:-$black}           # Defaults to black, if not specified.

  echo -e "$color$message\033[39m"

  return
}


# Now, let's try it out.
# ----------------------------------------------------
cecho "black" $black
cecho "red" $red
cecho "green" $green
cecho "yellow" $yellow
cecho "blue" $blue
cecho "magenta" $magenta
cecho "cyan" $cyan
cecho "white" $white
cecho "yellow_green" $yellow_green

cecho "No color passed (defaults to black)."
       # Missing $color argument.
cecho "\"Empty\" color passed (defaults to black)." ""
       # Empty $color argument.
cecho
       # Missing $message and $color arguments.
cecho "" ""
       # Empty $message and $color arguments.
# ----------------------------------------------------

echo

exit 0

# Exercises:
# ---------
# 1) Add the "bold" attribute to the 'cecho ()' function.
# 2) Add options for colored backgrounds.