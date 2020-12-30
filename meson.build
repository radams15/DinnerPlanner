project('DinnerPlannerGui', 'c')

sqlite = subproject('sqlite')

dependencies = [
	dependency('gtk+-3.0'),
	dependency('libcurl'),
	sqlite.get_variable('sqlite_dep')
]

files = [
    'src/main.c',
    'src/network.c',
    'src/recipes.c',
    'src/gui.c',
    'src/db.c'
]

executable('DinnerPlanner', files, dependencies : dependencies)
