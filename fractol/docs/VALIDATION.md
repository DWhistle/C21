# Validation record

Date: 2026-09-12. Baseline: `948232a` on `master`.
Host: Apple Silicon macOS; Apple Clang and system Make.

| Check | Result |
| --- | --- |
| Original `make` | Failed: `mlx.h` missing from compiler include path |
| Include-path-corrected native `make` | C compilation succeeded; linker failed because vendored MiniLibX/X11 and original libft archive target x86_64 rather than arm64 |
| `make -B -C libft/libft` | Passed: source library rebuilt with `-Wall -Wextra -Werror` |
| Clean library followed by `make CC='cc -arch x86_64'` | Passed: source libft, all application C files, and executable linked successfully |
| `clang -x cl -cl-std=CL1.2 -fsyntax-only mandel.cl` | Failed: compiler target lacks `cl_khr_fp64`/`double8` support |
| Same check for `julia.cl` | Failed for the same double-precision requirement |
| Actual `./fractol -m` launch | No graphical success verified; launch stalled in the host execution environment and termination was requested |
| CPU terrain GUI | Not completed after the stalled first launch; no rendered output verified |
| Runtime dependency inspection | Executable requires `/opt/X11/lib/libX11.6.dylib` and `libXext.6.dylib`; `/opt/X11` is absent |
| Subject integrity | 11-page PDF parses; SHA-256 matches pre-migration baseline exactly |
| Tests | No Fractol automated test suite was found |

OpenCL program compilation occurs at runtime, so a successfully linked C
executable does not establish a usable kernel/device combination. The GPU path
has a source-visible work-item/byte-count bounds defect documented in the
README and was not validated. The CPU terrain mode is distinct from a
Mandelbrot/Julia fallback.

The Makefiles now honor `CC` in parent/child compilation and locate the existing
MiniLibX header. No rendering algorithm or dependency version was changed.
The main executable and `libft/libft/libft.a` were removed from tracking only
after successful source rebuilds. No tracked `.o` files were present at baseline;
newly generated objects are ignored. One Finder metadata file was removed.
`liba.a`, `libft/libft/a.out`, and vendored graphics binaries remain because their
exact regeneration from the tracked Makefiles was not established. No author
file, source header, or dependency notice was removed.

A targeted source scan found no credential candidate; this is not a complete
history audit. No credential-rotation action is identified for this task.
