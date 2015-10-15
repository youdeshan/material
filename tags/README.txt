These three shell scripts are used to generate tags files for a project.
  sys_tags  -- to generate system library tags(c && c++)
  dir_tags_global -- to generate project scope tags(used to locate tag cross folders)
  dir_tags_recursive  -- to generate tags file for directory which includes .[ch] files recursively

Steps to set up an IDE with tags:
1. copy these 3 shell scripts to a folder and add this folder path to the $PATH variable
   eg: in ~/.bashrc add: PATH=$PATH:~/tools

2. generate the system scope tags file(used by all projects)
   2.1 run command: sys_tags, it will generate ~/share/tags file(hard code)
   2.2 add the tags file path to tags option in .vimrc:
       set tags+=~/share/tags

3. generate tags files for specific project
   3.1 export ROOT=%proj root path% 
       the $ROOT variable will be used by project make and dir_tags_global 
   3.2 cd $ROOT
   3.3 dir_tags_global $ROOT
   3.4 dir_tags_recursive $ROOT

Now, you can read the project source code and press C-] to locate tags.

4. Update tags files when you add, delete, modify source files
   4.1 to update the tags file in the directory of current editing file, add the following key map in .vimrc:
       :nmap <leader>c :!(cd %:p:h;ctags --sort=foldcase --c-kinds=+l --extra=+f
               *.[ch])&<CR><CR>
   4.2 to update the tags file in the project root directory, add the following key map in .vimrc:
       :nmap <leader>r :!(dir_tags_global $ROOT)&<CR><CR>

Perfectly, you can use the VIM as a real IDE.
Enjoy it!!!
