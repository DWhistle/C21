# Subject provenance

- Subject name: **FDF** (title on the first page).
- Project: `C21/fdf`, height-map wireframe viewer.
- Original repository path: `fdf.en.pdf` at repository root.
- Baseline commit: `948232abfdf0e59a5c80deeea73484120b2e3945`.
- Migration date: **2026-09-12**.
- Destination: [`subject.pdf`](subject.pdf), moved with `git mv`.
- SHA-256: `189f674bae9991bc6234bcf02b77809289553a4c3d4c3eeb18c04648b767c879`.
- Size: 2,107,799 bytes; 13 pages; unencrypted PDF 1.4.

The existing file was read and its checksum verified against the original file.
It was not downloaded, rewritten, OCRed, or otherwise modified.

The mandatory section describes a wireframe landscape loaded from a filename,
with grid positions supplying horizontal coordinates and values supplying height.
It specifies an executable named `fdf`, a Makefile, MiniLibX, and Escape exit.
The source has those corresponding entry points, map parsing,
point-to-segment drawing, MiniLibX use, and key code 53 exit. The subject permits
choosing the projection; the implementation uses rotated coordinates with parallel
screen projection. This is strong evidence that the repository's existing FDF
subject belongs with this subproject.

No external assignment-version, cohort, official result, or individual authorship
record was verified. Matching the assignment does not establish full compliance
with its requirements. PDF metadata lists a 2017 creation date, which is metadata,
not a claim about when the coursework was completed. The file remains readable
through Poppler and pypdf; pypdf reported recoverable cross-reference warnings.
