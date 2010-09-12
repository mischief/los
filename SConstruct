import os
import platform

opts = Variables('scache.conf')

warnflags = ""
warnflags += " -Wall -Wextra -Wundef -Wmissing-declarations -Wredundant-decls "
warnflags += " -Wlong-long -Wfloat-equal "
warnflags += " -Waggregate-return -Wcast-align -Wcast-qual -Wchar-subscripts -Wcomment " #-Wconversion "
warnflags += " -Wno-deprecated-declarations -Wdisabled-optimization -Wno-div-by-zero -Wno-endif-labels "
warnflags += " -Wfloat-equal -Wformat -Wformat=2 "
warnflags += " -Wno-format-extra-args -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wimplicit "
warnflags += " -Wimport -Wno-import -Winit-self "
warnflags += " -Winline -Winvalid-pch -Wlong-long -Wmissing-braces "
warnflags += " -Wmissing-field-initializers -Wmissing-format-attribute "
warnflags += " -Wmissing-noreturn -Wno-multichar -Wpacked -Wparentheses "
warnflags += " -Wpointer-arith -Wredundant-decls -Wreturn-type -Wsequence-point -Wshadow -Wsign-compare "
warnflags += " -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch "
warnflags += " -Wsystem-headers -Wtrigraphs"

cwarnflags = " -Wnested-externs -Wbad-function-cast -Werror-implicit-function-declaration -Wimplicit-function-declaration -Wimplicit-int -Wnonnull"

opts.AddVariables(
    ('AR', 'Set the archiver name'),
    ('RANLIB', 'Set the archive indexer name'),
    ('CC', 'Set the C compiler name'),
    ('CXX', 'Set the C++ compiler name'),
    ('AS', 'Set the assembler name'),
    ('LINK', 'Set the linker name'),
    ('CFLAGS', 'Set the C compiler flags', warnflags+cwarnflags+' -nostdlib -ffreestanding -Isrc/include -std=c99'),
    ('CXXFLAGS', 'Set the C++ compiler flags', warnflags+' -Wno-write-strings -nostdlib -fno-builtin -nostartfiles -nodefaultlibs -fno-exceptions -fno-rtti -fno-stack-protector -Isrc/include'),
    ('ASFLAGS', 'Set the assembler flags', warnflags+cwarnflags+' -nostdlib -ffreestanding -Isrc/include'),
    ('LINKFLAGS', 'Set the linker flags', '-nostdlib'),
    EnumVariable('optimization', 'Set optimization level. 0 1 2 or 3', '1', allowed_values=('0','1','2','3')),
    ('BUILDDIR', 'Set the sub-directory to put object files in', 'build'),
    BoolVariable('verbose', 'Show full commands during the build process', False),
    ('arch', 'Set the target architecture', 'x86'),
    BoolVariable('debug', 'Enable debugging symbols', False),
)

env = Environment(options = opts, ENV = os.environ)
Help(opts.GenerateHelpText(env))
opts.Save('scache.conf', env)

env.Append(CFLAGS = ' -O' + env['optimization'])
env.Append(ASFLAGS = ' -DASSEMBLER ')

if env['debug'] == 1:
  env['CFLAGS'] += " -g "
  env['CXXFLAGS'] += " -g "

if env['verbose'] != 1:
  env['ARCOMSTR'] = "$AR $TARGET"
  env['ASCOMSTR'] = "$AS $TARGET"
  env['ASPPCOMSTR'] = "$AS $TARGET"
  env['CCCOMSTR'] = "$CC $TARGET"
  env['CXXCOMSTR'] = "$CXX $TARGET"
  env['LINKCOMSTR'] = "$LINK $TARGET"
  env['RANLIBCOMSTR'] = "$RANLIB $TARGET"

SConscript('SConscript', exports='env', variant_dir = env['BUILDDIR'] , duplicate = 0 )

Clean('.', [ env['BUILDDIR'] ] )
