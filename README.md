# Computer Science @ KU Leuven

All important course material I created for my Computer Science degree at KU Leuven.\
This repo includes most (non-trivial) exams I have taken, as well as other useful material (summaries, notes, exercises, etc.).

## Content

### BSc

-   **KU Leuven** campus Kulak Kortrijk (`/KULAK`)

    | **Semester** | **Courses**                                                                                                                                  |
    | ------------ | -------------------------------------------------------------------------------------------------------------------------------------------- |
    | B1S1         | Analyse & Calculus, Beginselen van Programmeren, Conceptuele Natuurkunde, Fundamenten voor de Informatica, Wiskundig Redeneren               |
    | B1S2         | Lineaire Algebra, Statistiek, Technieken voor Wiskundige Analyse                                                                             |
    | B2S1         | Automaten & Berekenbaarheid, Elektrische Netwerken, Gegevensstructuren & Algoritmen, Informatieoverdracht en -verwerking, Numerieke Wiskunde |
    | B2S2         | Declaratieve Talen, Wijsbegeerte                                                                                                             |
    | B3S1         | ...                                                                                                                                          |

-   Exchange semester @ **DTU - Technical University of Denmark** (`/DTU`)
    -   Deep Learning
    -   Operating Systems
    -   Discrete Mathematics II: Algebra (groups, rings and fields)
    -   Introductory Economics
    -   Machine Learning

### MSc

-   Master of Engineering: Computer Science (Leuven)

## Getting started

### LaTeX resources

There is always a `.pdf` file accompanying each `.tex` file.
In case you want to compile the LaTeX files yourself, you can follow the instructions below.

#### LaTeX setup

1. Make sure you have a LaTeX distribution installed. You can use [TeX Live](https://www.tug.org/texlive/) (cross-platform), [MiKTeX](https://miktex.org/) (Windows), or [MacTeX](https://tug.org/mactex/) (macOS).
2. Use a dedicated LaTeX editor like [TeXstudio](https://www.texstudio.org/), or install the _incredible_ [LaTeX Workshop extension](https://marketplace.visualstudio.com/items?itemName=James-Yu.latex-workshop) for [Visual Studio Code](https://code.visualstudio.com/) that I recently started using (you get Copilot completions this way!).

#### Templates

Templates for DTU are included in all folders (`dtuarticle.cls`, `dtulogo.pdf`, etc.).
Kulak templates, on the other hand, can be installed from [here](https://github.com/srebry/KULeuvenLaTeXClasses). This repository also contains fantastic instructions on how to set up your LaTeX environment on your machine.

---

### Obsidian Notes

Some notes were created using Obsidian, which uses Markdown files. A normal MD renderer will not display the notes correctly. If you want to view or edit these notes, you can use Obsidian as follows:

#### Installing Obsidian

1. Go to the [Obsidian website](https://obsidian.md/).
2. Download the installer for your operating system (Windows, macOS, or Linux).
3. Run the installer and follow the on-screen instructions to complete the installation.

#### Installing packages

I used the following community plugins in Obsidian:

-   **Dataview**
-   **LaTeX suite**
-   **Extended MathJax** (for custom `preamble.sty`)

#### Opening the vault

After installing Obsidian, you can open the vault by selecting _"Open folder as vault"_ and choosing the corresponding folder in this repository.
Normally, the `.obsidian` folder is loaded, too, which should automatically enable the correct plugins. If not, you can enable them manually via _Settings > Community plugins_.
