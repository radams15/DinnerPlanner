project('DinnerPlannerGui', 'cpp')

sqlite = subproject('sqlite')

dependencies = [
	dependency('gtk+-3.0'),
	dependency('libcurl'),
	sqlite.get_variable('sqlite_dep')
]

files = [
    'src/main.cpp',
    'src/network.cpp',
    'src/recipes.cpp',
    'src/gui.cpp'
]

executable('DinnerPlanner', files, dependencies : dependencies)
