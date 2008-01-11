package.name = "mathlib"
package.kind = "lib"
package.language = "c++"
--package.buildflags = {""}
--package.includepaths = {""}
--package.libpaths = {""}
--package.links = {""}

--options
--addoption("name", "description"

package.files = {
	matchfiles("*.cpp", "*.h")
}
