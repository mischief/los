import os
import platform

opts = Variables('scache.conf')

warnflags = " -Wall "
#warnflags += " -Wall -Wextra -Wundef -Wredundant-decls " # -Wmissing-declarations
#~ warnflags += " -Wlong-long -Wfloat-equal "
#warnflags += " -Waggregate-return -Wcast-align -Wcast-qual -Wchar-subscripts -Wcomment " #-Wconversion "
#warnflags += " -Wno-deprecated-declarations -Wdisabled-optimization -Wno-div-by-zero -Wno-endif-labels "
#~ warnflags += " -Wfloat-equal -Wformat -Wformat=2 "
#~ warnflags += " -Wno-format-extra-args -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wimplicit "
#~ warnflags += " -Wimport -Wno-import -Winit-self "
#~ warnflags += " -Winvalid-pch -Wlong-long -Wmissing-braces "
#warnflags += " -Winline "
#~ warnflags += " -Wmissing-field-initializers -Wmissing-format-attribute "
#~ warnflags += " -Wno-multichar -Wpacked -Wparentheses " # -Wmissing-noreturn
#~ warnflags += " -Wpointer-arith -Wredundant-decls -Wreturn-type -Wsequence-point -Wshadow -Wsign-compare "
#~ warnflags += " -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch "
#~ warnflags += " -Wsystem-headers -Wtrigraphs"

cwarnflags = ""
#~ cwarnflags = " -Wnested-externs -Wbad-function-cast -Werror-implicit-function-declaration -Wimplicit-function-declaration -Wimplicit-int -Wnonnull"

opts.AddVariables(
    ('AR', 'Set the archiver name'),
    ('RANLIB', 'Set the archive indexer name'),
    ('CC', 'Set the C compiler name'),
    ('CXX', 'Set the C++ compiler name'),
    ('AS', 'Set the assembler name'),
    ('LINK', 'Set the linker name'),
    ('CFLAGS', 'Set the C compiler flags', warnflags+cwarnflags+'-nostdinc -ffreestanding -std=gnu99 -pipe'),
    ('CXXFLAGS', 'Set the C++ compiler flags', warnflags+' -nostdlib -fno-builtin -nostartfiles -nodefaultlibs -fno-exceptions -fno-rtti -fno-stack-protector'),
    ('ASFLAGS', 'Set the assembler flags', warnflags+cwarnflags+'-nostdlib -ffreestanding'),
    ('LINKFLAGS', 'Set the linker flags', '-nostdlib'),
    EnumVariable('optimization', 'Set optimization level. s 0 1 2 or 3', '1', allowed_values=('s','0','1','2','3')),
    ('BUILDDIR', 'Set the sub-directory to put object files in', '.build'),
    BoolVariable('verbose', 'Show full commands during the build process', False),
    ('arch', 'Set the target architecture', 'x86'),
    ('serial', 'Set to use serial port 1 for stdio', False),
    BoolVariable('debug', 'Enable debugging symbols', False),
)

env = Environment(options = opts, ENV = os.environ)
Help(opts.GenerateHelpText(env))
opts.Save('scache.conf', env)

env.MergeFlags(' -O' + env['optimization'])
env.Append(ASFLAGS = ' -DASSEMBLER ')
env.Append(CPPPATH = ['#/include', '#/src', '#/include/oskit/c'])

# Link the current arch's include dir to oskit/machine

def buildlink(env, name, target):
  """Links target to name"""
  import shlex, subprocess
  command = 'ln -f -n -s %s %s' % (target, name)
#  print command
  subprocess.Popen(shlex.split(command))
  return None

env.AddMethod(buildlink, "BuildLink")

archinclude = 'include/oskit/machine'
archdir = env['arch']

env.BuildLink(archinclude, archdir)

if env['debug']:
  env.MergeFlags(['-g', '-O0', '-fkeep-inline-functions', '-finline-functions'])
  env.MergeFlags('-DDEBUG')

if env['serial']:
  env.MergeFlags('-DUSE_SERIAL')

if not env['verbose']:
  env['ARCOMSTR'] = "$AR\t $TARGET"
  env['ASCOMSTR'] = "$AS\t $TARGET"
  env['ASPPCOMSTR'] = "$AS\t $TARGET"
  env['CCCOMSTR'] = "$CC\t $TARGET"
  env['CXXCOMSTR'] = "$CXX\t $TARGET"
  env['LINKCOMSTR'] = "$LINK\t $TARGET"
  env['RANLIBCOMSTR'] = "$RANLIB\t $TARGET"

SConscript('SConscript', exports='env', variant_dir = env['BUILDDIR'] , duplicate = 0 )

Clean('.', [ env['BUILDDIR'], archinclude ] )
