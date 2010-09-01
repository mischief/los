import os
Import(['env'])

subdirs = ['src']

env.kernel_objects = []

SConscript([os.path.join(i, 'SConscript') for i in subdirs], exports = ['env'])

kernel = env.Program('kernel',
  env.kernel_objects,
  LINKFLAGS = env['LINKFLAGS'] + ' -T' + os.path.join(Dir('.').srcnode().path, 'src/link.ld')
)

env.Depends(kernel, '#/src/link.ld')
