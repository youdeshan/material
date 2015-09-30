
INSTALL
=======
The Monaco font is used for terminal, but the 'Monaco_Linux-Powerline.ttf' also
a patched font for powerline plugin of vim(it includes the symbols for powerline).

1. cp Monaco_Linux-Powerline.ttf ~/.fonts
2. fc-cache -vf ~/.fonts
3. open terminal 'Profile Preferences', General -> Font, select 'Monaco for
   Powerline'

If you're using urxvt add something like this to your ~/.Xresources or ~/.Xdefaults::

    URxvt*font:                 xft:Monaco for Powerline:regular:size=8
    URxvt*imFont:               xft:Monaco for Powerline:regular:size=8
    URxvt*boldFont:             xft:Monaco for Powerline:bold:size=8
    URxvt*italicFont:           xft:Monaco for Powerline:italic:size=8
    URxvt*boldItalicFont:       xft:Monaco for Powerline:bold:italic:size=8


Make sure to run ``xrdb -merge ~/.Xresources`` afterwards and close all urxvt terminals.


