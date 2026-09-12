# Validation record

Date: 2026-09-12. Baseline: `948232abfdf0e59a5c80deeea73484120b2e3945`.
Isolated worktree branch: `docs/42-fdf-portfolio`. Host: macOS Darwin 24.3.0.

## Baseline

- No subproject README or automated tests were supplied; 15 existing `.fdf` maps.
- `make -C fdf` failed with `mlx.h` not found. The Makefile's compilation include
  path omitted the existing `includes/X11/include` directory.
- Tracked executable: Intel x86_64 Mach-O. The supplied X11 dylibs include x86_64;
  MiniLibX source is not provided with its archives.
- Tracked project object and libft archive were generated from present sources.
- The large copied X11 tree contains libraries, tools, headers, fonts, manuals,
  Python 2.6 sources, bytecode, and third-party attribution.

## Build and execution

- Added the existing MiniLibX header search path.
- Replaced hard-coded compiler calls with `$(CC)` and forwarded recursive make via
  `$(MAKE)`; the libft Makefile also honors `CC`.
- Included `get_next_line.o` in clean/fclean and made output removal idempotent.
- `make -C fdf CC='clang -arch x86_64'`: passed after rebuilding libft from source,
  compiling all project units, and linking the executable.
- `./fdf/fdf fdf/test_maps/42.fdf`: attempted; loader terminated with missing
  `/opt/X11/lib/libX11.6.dylib`. `/opt/X11` and an X11 `DISPLAY` were unavailable.
- No graphical interaction or screenshot was possible. No claim of a passing map
  render, native ARM build, Linux build, sanitizer run, or performance measurement.

## Cleanup evidence

The project executable, `get_next_line.o`, and `libft/libft/libft.a` were removed
from tracking only after the complete Intel build succeeded. Ignore rules cover
their regenerated locations. Sixty-two `.pyc`/`.pyo` files were removed from the
copied X11 tree only where matching `.py` source exists.

All other vendor binaries were preserved. A reproducible source-based replacement
for the supplied MiniLibX archives has not been established, and deleting the tree
would break the verified link step. No source authorship headers or license files
were removed. No credentials were identified in the inspected project sources and
configuration; this was not a repository-wide security scan.

## Source-level limitations retained

- `ft_strlen2dim` uses a local counter before initialization (`stash.c`).
- Uncolored input points do not initialize the `color` member (`read_from_the_file.c`).
- `set_camera` does not initialize the mouse-follow flag `r` (`libx.c`).
- Input/allocation failure handling and memory/file-descriptor cleanup are incomplete.
- Redraw calls re-enter `draw_the_map`, which sets hooks and invokes `mlx_loop`.
- Project rebuilds are unconditional and libft lacks comprehensive source dependencies.

The input parser and renderer were not rewritten or silently repaired. The README
reports these limitations so the successful compilation cannot be mistaken for
behavioral verification.
