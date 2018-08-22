function varargout = table_students(varargin)
% TABLE_STUDENTS MATLAB code for table_students.fig
%      TABLE_STUDENTS, by itself, creates a new TABLE_STUDENTS or raises the existing
%      singleton*.
%
%      H = TABLE_STUDENTS returns the handle to a new TABLE_STUDENTS or the handle to
%      the existing singleton*.
%
%      TABLE_STUDENTS('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TABLE_STUDENTS.M with the given input arguments.
%
%      TABLE_STUDENTS('Property','Value',...) creates a new TABLE_STUDENTS or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before table_students_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to table_students_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help table_students

% Last Modified by GUIDE v2.5 16-Aug-2018 16:08:13

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @table_students_OpeningFcn, ...
                   'gui_OutputFcn',  @table_students_OutputFcn, ...
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


% --- Executes just before table_students is made visible.
function table_students_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to table_students (see VARARGIN)

% Choose default command line output for table_students
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes table_students wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = table_students_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes during object creation, after setting all properties.
function studentTable_CreateFcn(hObject, eventdata, handles)
% hObject    handle to studentTable (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
col_labels = {'学号', '姓名', '性别', '语文', '数学', '英语', '是否优秀'};
data = {'2010601', 'youdeshan', '男', 98, 100, 89, true; ...
    '2010602', 'steven', '男', 98, 100, 89, true; ...
    '2010603', 'jeff', '男', 98, 100, 89, true; ...
    '2010604', 'andy', '男', 98, 100, 89, true; ...
    '2010605', 'ralph', '男', 98, 100, 89, true};
set(hObject, 'ColumnName', col_labels);
set(hObject, 'Data', data);
set(hObject, 'ColumnEditable', [false, false, false, true, true, true, true]);
%hObject.ColumnEditable = true;


% --- Executes when entered data in editable cell(s) in studentTable.
function studentTable_CellEditCallback(hObject, eventdata, handles)
% hObject    handle to studentTable (see GCBO)
% eventdata  structure with the following fields (see MATLAB.UI.CONTROL.TABLE)
%	Indices: row and column indices of the cell(s) edited
%	PreviousData: previous data for the cell(s) edited
%	EditData: string(s) entered by the user
%	NewData: EditData or its converted form set on the Data property. Empty if Data was not changed
%	Error: error string when failed to convert EditData to appropriate value for Data
% handles    structure with handles and user data (see GUIDATA)
set(handles.cellValueText, 'String', ['Old value: ', num2str(eventdata.PreviousData), ', New value: ', num2str(eventdata.NewData)]);


% --- Executes when selected cell(s) is changed in studentTable.
function studentTable_CellSelectionCallback(hObject, eventdata, handles)
% hObject    handle to studentTable (see GCBO)
% eventdata  structure with the following fields (see MATLAB.UI.CONTROL.TABLE)
%	Indices: row and column indices of the cell(s) currently selecteds
% handles    structure with handles and user data (see GUIDATA)
row_index = eventdata.Indices(1);
col_index = eventdata.Indices(2);
set(handles.posText, 'String', ['Pos: (', num2str(row_index), ', ', num2str(col_index), ')']);

table_data = get(hObject, 'Data');
cell_val = table_data(row_index, col_index);
set(handles.cellValueText, 'String', cell_val);
