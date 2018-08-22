function dragDemo
%% Demonstrate dragging patch objects
% and manipulating with keys
% Author: Dodge Flannelette
figure(1)

%% draw two patch objects
axis([0, 10, 0, 5]);
hpatch(1)=patch([1, 2, 2, 1, 1],[2.2, 2, 3.2, 3, 2.2],'r');
hpatch(2)=patch([5, 8, 9, 5, 5],[2.2, 2, 3.2, 3, 2.2], 'g');
%% set callbacks for button down, up, and keypresses
set(hpatch(1), 'ButtonDownFcn', @patchButtonDown);
set(hpatch(2), 'ButtonDownFcn', @patchButtonDown);
set(gcf, 'WindowButtonUpFcn', @ButtonUp);
set(gcf, 'KeyPressFcn', @processKey);

%% Button Functions
function patchButtonDown(hpatch, eventdata)
curr_pt = get(gca, 'CurrentPoint');
previous_pt=[curr_pt(1, 1), curr_pt(1, 2)];

% set the WindowButtonMotionFcn and give it 2 additional
% arguments: the patch handle and the offset
setappdata(gcf, 'SelectedPatch', hpatch);
setappdata(gcf, 'previous_point', previous_pt);
set(gcf, 'WindowButtonMotionFcn', ...
    {@figButtonMotion, hpatch});

function figButtonMotion(src, eventdata, hselected)
% Moves the object with handle hselected.
% The offset is the difference between the lower left
% of the object and the mouse position when button
% was pushed down.
% Get position of vertices
x=get(hselected, 'XData');
y=get(hselected, 'YData');

% Get the mouse cursor Location
curr_pt = get(gca, 'CurrentPoint');
last_pt = [curr_pt(1, 1), curr_pt(1, 2)];
previous_pt = getappdata(gcf, 'previous_point');
delta_pt = last_pt - previous_pt;

set(hselected, 'XData', delta_pt(1) + x);
set(hselected, 'YData', delta_pt(2) + y);

setappdata(gcf, 'previous_point', last_pt);

function ButtonUp(src, eventdata);
% when the button is released, turn off the motion function
set(gcf, 'WindowButtonMotionFcn', ' ')

function processKey(src, evnt)
% process arrow keys to move currently selected patch
hpatch=getappdata(gcf, 'SelectedPatch');
if length(evnt.Key)>=1
xshift=0;
yshift=0;
switch evnt.Key
case 'leftarrow'
xshift=-0.1;
case 'rightarrow'
xshift= 0.1;
case 'uparrow'
yshift= 0.1;
case 'downarrow'
yshift= -0.1;
end
x=get(hpatch, 'XData')+xshift;
set(hpatch, 'XData', x);
y=get(hpatch, 'YData')+yshift;
set(hpatch, 'YData', y);
end