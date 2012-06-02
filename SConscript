import os.path
Import(['env'])

subdirs = ['src', 'lua']
env.razor = []

SConscript([os.path.join(i, 'SConscript') for i in subdirs], exports = ['env'])

SConscript('example/SConscript', exports = ['env'])
