import os.path
Import(['env'])

subdirs = ['src']
env.razor = []

SConscript([os.path.join(i, 'SConscript') for i in subdirs], exports = ['env'])

#kernel = env.Program('razor', env.razor_objects, LINKFLAGS = env['LINKFLAGS'] + ' -T' + os.path.join(Dir('.').srcnode().path, 'src/link.ld') )
#env.Depends(kernel, 'src/link.ld')

SConscript('example/SConscript', exports = ['env'])
