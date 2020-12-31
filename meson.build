project('DinnerPlannerGui', 'cpp')

sqlite = subproject('sqlite')

dependencies = [
	dependency('gtkmm-3.0'),
	dependency('libcurl'),
	sqlite.get_variable('sqlite_dep')
]

files = [
    'src/main.cpp',
    'src/Network.cpp',
    'src/DB.cpp',
    'src/Recipe_View.cpp'
]

executable('DinnerPlanner', files, dependencies : dependencies)
