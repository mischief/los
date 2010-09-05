import os
import platform

opts = Variables('scache.conf')

warnflags = ""
warnflags += " -Wall -Wextra -Wundef -Wbad-function-cast -Wmissing-declarations -Wredundant-decls "
warnflags += " -Wnested-externs -Wlong-long -Wfloat-equal "
warnflags += " -Waggregate-return -Wcast-align -Wcast-qual -Wchar-subscripts -Wcomment -Wconversion "
warnflags += " -Wno-deprecated-declarations -Wdisabled-optimization -Wno-div-by-zero -Wno-endif-labels "
warnflags += " -Werror-implicit-function-declaration -Wfloat-equal -Wformat -Wformat=2 "
warnflags += " -Wno-format-extra-args -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wimplicit "
warnflags += " -Wimplicit-function-declaration -Wimplicit-int -Wimport -Wno-import -Winit-self "
warnflags += " -Winline -Winvalid-pch -Wlong-long -Wmissing-braces "
warnflags += " -Wmissing-field-initializers -Wmissing-format-attribute "
warnflags += " -Wmissing-noreturn -Wno-multichar -Wnonnull -Wpacked -Wparentheses "
warnflags += " -Wpointer-arith -Wredundant-decls -Wreturn-type -Wsequence-point -Wshadow -Wsign-compare "
warnflags += " -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch "
warnflags += " -Wsystem-headers -Wtrigraphs "

opts.AddVariables(
    ('CC', 'Set the C compiler name'),
    ('AS', 'Set the assembler name'),
    ('LINK', 'Set the linker name'),
    ('CFLAGS', 'Set the C compiler flags', warnflags+' -nostdlib -ffreestanding -Isrc/include -std=c99'),
    ('ASFLAGS', 'Set the assembler flags', warnflags+' -nostdlib -ffreestanding -Isrc/include'),
    ('LINKFLAGS', 'Set the linker flags', '-nostdlib'),
    EnumVariable('optimization', 'Set optimization level. 0 1 2 or 3', '1', allowed_values=('0','1','2','3')),
    ('BUILDDIR', 'Set the sub-directory to put object files in', 'build'),
    BoolVariable('VERBOSE', 'Show full commands during the build process', False),
    ('arch', 'Set the target architecture', 'i386'),
)

env = Environment(options = opts, ENV = os.environ)
Help(opts.GenerateHelpText(env))
opts.Save('scache.conf', env)

env.Append(CFLAGS = ' -O' + env['optimization'])

SConscript('SConscript', exports='env', variant_dir = env['BUILDDIR'] , duplicate = 0 )

Clean('.', [ env['BUILDDIR'] ] )
