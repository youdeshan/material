function varargout = DampedEfieldTool(varargin)
% DAMPEDEFIELDTOOL MATLAB code for DampedEfieldTool.fig
%      DAMPEDEFIELDTOOL, by itself, creates a new DAMPEDEFIELDTOOL or raises the existing
%      singleton*.
%
%      H = DAMPEDEFIELDTOOL returns the handle to a new DAMPEDEFIELDTOOL or the handle to
%      the existing singleton*.
%
%      DAMPEDEFIELDTOOL('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in DAMPEDEFIELDTOOL.M with the given input arguments.
%
%      DAMPEDEFIELDTOOL('Property','Value',...) creates a new DAMPEDEFIELDTOOL or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before DampedEfieldTool_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to DampedEfieldTool_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help DampedEfieldTool

% Last Modified by GUIDE v2.5 16-Aug-2018 13:44:59

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @DampedEfieldTool_OpeningFcn, ...
                   'gui_OutputFcn',  @DampedEfieldTool_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before DampedEfieldTool is made visible.
function DampedEfieldTool_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to DampedEfieldTool (see VARARGIN)

% Choose default command line output for DampedEfieldTool
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes DampedEfieldTool wait for user response (see UIRESUME)
% uiwait(handles.figure1);

% Call self-defined function
plotDampedEfieldF(handles);


% --- Outputs from this function are returned to the command line.
function varargout = DampedEfieldTool_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on slider movement.
function depthSlider_Callback(hObject, eventdata, handles)
% hObject    handle to depthSlider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider
set(handles.depthText, 'String', get(handles.depthSlider, 'Value'));
plotDampedEfieldF(handles);


% --- Executes during object creation, after setting all properties.
function depthSlider_CreateFcn(hObject, eventdata, handles)
% hObject    handle to depthSlider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function depthText_Callback(hObject, eventdata, handles)
% hObject    handle to depthText (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of depthText as text
%        str2double(get(hObject,'String')) returns contents of depthText as a double
set(handles.depthSlider, 'Value', str2double(get(handles.depthText, 'String')));
plotDampedEfieldF(handles);


% --- Executes during object creation, after setting all properties.
function depthText_CreateFcn(hObject, eventdata, handles)
% hObject    handle to depthText (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in gridCheckbox.
function gridCheckbox_Callback(hObject, eventdata, handles)
% hObject    handle to gridCheckbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of gridCheckbox
hax = handles.plotAxes;
show_grid = get(handles.gridCheckbox, 'Value');
if show_grid
  grid(hax, 'on');
else
  grid(hax, 'off');
end


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1


% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

%Steps to create the callback of buttongroup(Steven)
%   1. select the buttongroup
%   2. view -> view callbacks -> SelectionChangeFcn
 
% --- Executes when selected object is changed in companyBtnGroup.
function companyBtnGroup_SelectionChangedFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in companyBtnGroup 
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
select_obj = get(handles.companyBtnGroup, 'SelectedObject');
select_obj_tag = get(select_obj, 'Tag');
switch select_obj_tag
    case 'carestreamTButton'
        set(handles.companyText, 'String', ['This is my favorite company: ', get(select_obj, 'String')]);
    case 'datuTButton'
        set(handles.companyText, 'String', ['This is a passion company: ', get(select_obj, 'String')]);
    case 'lubanTButton'
        set(handles.companyText, 'String', ['This is my started company: ', get(select_obj, 'String')]);
end
     
        
