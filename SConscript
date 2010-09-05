import os.path
Import(['env'])

subdirs = ['src']

env.kernel_objects = []

SConscript([os.path.join(i, 'SConscript') for i in subdirs], exports = ['env'])

kernel = env.Program('razor', env.kernel_objects,
  LINKFLAGS = env['LINKFLAGS'] + ' -T' + os.path.join(Dir('.').srcnode().path, 'src/link.ld')
)

Copy(kernel, '#/pee')

env.Depends(kernel, 'src/link.ld')
