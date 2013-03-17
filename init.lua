--los = require('los')

package.path = '?.lua;/?.lua'

-- LOS
print("Multiboot info:")
print("Command line:", los.cmdline)
print("Lower memory:", los.mem_lower)
print("Upper memory:", los.mem_upper)
print("Boot modules:", table.concat(los.bmods, " "))

print("")
print("Lua OS version", los.los_version, "and", "OSKIT version", los.oskit_version)
print("http://github.com/mischief/los")
print("")
print("Starting shell. Run os.exit() to shutdown the machine.")
print("Check the los table for OS information.")

shell = assert(require('shell'))
shell.start()
