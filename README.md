# Programming Massively Parallel Hardware (PMPH), Block 1, 2026

### We are grateful to Nvidia for awarding a teaching grant (for the PMPH and DPP courses) that consists of two A100 GPUs. These are now accessible on the Hendrix GPU cluster.

## Course Structure

PMPH is structured to have four hours of (physical) lectures
and four hours of (physical) labs per week; potentially we
will have no lectures in the last few weeks of the course, so you
can concentrate on project work (to be announced).

[Course Catalog Web Page](https://kurser.ku.dk/course/ndak14008u/2026-2027)

### Lectures:

* Monday    13:00 - 15:00 (aud - Aud 06, Universitetsparken 5, HCØ)
* Wednesday 10:00 - 12:00 (aud - Aud 06, Universitetsparken 5, HCØ)

### Labs:

* Monday    15:00 - 17:00 (øv - bib 4-0-17, Universitetsparken 1-3, DIKU)
* Wednesday 13:00 - 15:00 (øv - bib 4-0-17, Universitetsparken 1-3, DIKU)

### Flexible Schedule on Wednesday

For *Wednesdays*, we have also reserved the same room in continuation, 
from 15:00 -- 17:00, so that we can stay over if necessary.


### Physical Attendence to Lectures and Labs

The current plan is that everybody will have a physical place
at the lectures and labs. Unless we are forced to move to virtual
teaching (very unlikely), the lectures and labs will not be recorded,
so please plan to attend. If there is a strong request, we may stream
the lectures, but without providing any guarantees as to the quality
of streaming.

### Evaluation

Throughout the course, you will hand in six assignments, which will sum
up to 100 points. Final grades are computed according to the following scheme:
* $\geq$ 90 translates to grade 12
* $\geq$ 80 translates to grade 10
* $\geq$ 66 translates to grade  7
* $\geq$ 56 translates to grade  4
* $\geq$ 50 translates to grade  2
* $<$ 50 means fails, i.e., grade 0


For more information on weekly assignments and (re-)submission, please see [this
section](#assignments).

**The submission and re-submission of all Assignments is on Absalon. Please do NOT submit solutions on this Github Repo.**

### Teachers

Teachers: 

* **Cosmin Oancea** ([cosmin.oancea@diku.dk](mailto:cosmin.oancea@diku.dk)). Cosmin will hold the lectures and labs of PMPH.

Teaching assistants (TAs):
* **Cornelius Sevald-Krause** [e-mail](mailto:cornelius.sevald@protonmail.com)
* **Mark Mizzi** [e-mail](mailto:rtd992@alumni.ku.dk)

Mark and Cornelius will be (pre-)grading your first 4 assignments, will be patrolling the online (Absalon) discussion forums, and may assist in the lab sessions.

### Course Tracks and Resources

All lectures and lab sessions will be delivered in English.  The
assignments and projects will be posted in English, and while you can
chose to hand in solutions in either English or Danish, English is
preferred. All course material except for the hardware book is distributed
via this GitHub page. **Note: assignment handin is still on Absalon!**

* **The hardware track** of the course covers (lecture) topics related to processor, memory and interconnect design, including cache coherency, which are selected from the book [Parallel Computer Organization and Design, by Michel Dubois, Murali Annavaram and Per Stenstrom,  ISBN 978-521-88675-8. Cambridge University Press, 2012](https://www.cambridge.org/dk/academic/subjects/engineering/computer-engineering/parallel-computer-organization-and-design?format=HB&isbn=9780521886758). The book is available at the local bookstore (biocenter). It is not mandatory to buy it---Cosmin thinks that it is possible to understand the material from the lecture slides, which are detailed enough---but also note that lecture notes are not provided for the hardware track, because of copyright issues.

* **The software track** covers (lecture) topics related to parallel-programming models and recipes to recognize and optimize parallelism and locality of reference.  It demonstrates that compiler optimizations are essential to fully utilizing hardware, and that some optimizations can be implemented both in hardware and software, but with different pro and cons.  **The lecture notes are available here** [pdf](http://hjemmesider.diku.dk/~zgh600/Publications/lecture-notes-pmph.pdf), [bib](facultative-material/lecture-notes.bib). Additional (facultative) reading material (papers) will be linked with individual lectures; see Course Schedule Section below.

* **The lab track** teaches GPGPU hardware specifics and programming in Futhark, CUDA, and OpenMP. The intent is that the lab track applies in practice some of the parallel programming principles and optimizations techniques discussed in the software tracks. It is also intended to provide help for the weekly assignment, group project, etc.

## Course Schedule

This course schedule is tentative and will be updated as we go along. 
The links will become functional as we get near to the corresponding date.

The lab sessions are aimed at providing help for the assignments, i.e., the four weeklies and the group project.
It is not for granted that you are able to solve them without attending the (lectures and) lab sessions.

| Date | Time | Topic | Material |
| --- | --- | --- | --- |
| 31/08 | 13:00-15:00 | [Intro, Hardware Trends and List Homomorphisms (LH - SFT)](slides/L1-Intro-Org-LH.pdf), Chapters 1 and 2 in [Lecture Notes](http://hjemmesider.diku.dk/~zgh600/Publications/lecture-notes-pmph.pdf) | Facultative material: [Sergei Gorlatch, "Systematic Extraction and Implementation of Divide-and-Conquer Parallelism"](facultative-material/List-Hom/GorlatchDivAndConq.pdf);  [Richard S. Bird, "An Introduction to the Theory of Lists"](facultative-material/List-Hom/BirdThofLists.pdf); [Jeremy Gibons, "The third homomorphism theorem"](facultative-material/List-Hom/GibonsThirdTheorem.pdf) |
| 31/08 | 15:00-17:00 | [Gentle Intro to CUDA](slides/Lab1-CudaIntro.pdf) | [helper CUDA code](HelperCode/Lab-1-Cuda); as facultative material you may consult Cuda tutorials, for example [a very simple one is this one](https://developer.nvidia.com/blog/even-easier-introduction-cuda/) and [a more comprehensive one is this one](https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html)
| 02/09 | 10:00-12:00 | [List Homomorphism (LH) & Parallel Basic Blocks (SFT)](slides/L2-Flatenning.pdf), Chapters 2 and 3 in [Lecture Notes](http://hjemmesider.diku.dk/~zgh600/Publications/lecture-notes-pmph.pdf) | Facultative material: [Various papers related to SCAN and flattening, but which are not very accessible to students](facultative-material/Flattening) |
| 02/09 | 13:00-15:00 | Lab: [Futhark programming](HelperCode/README.md), First Weekly | [Futhark code related to the LH lecture](HelperCode/Lect-1-LH) and as well [Futhark code related to flattening](HelperCode/Lect-2-Flat). As facultative but useful material: [Parallel Programming in Futhark](https://futhark-book.readthedocs.io/en/latest/), sections 1-4, |
| 02/09 | some time   | [**Assignment 1 handout**](weeklies/assignment-1/) | |
| 07/09 | 13:00-15:00 | [Parallel Basic Block & Flattening Nested Parallelism (SFT)](slides/L2-Flatenning.pdf) | chapters 3 and 4 in [Lecture Notes](http://hjemmesider.diku.dk/~zgh600/Publications/lecture-notes-pmph.pdf) |
| 07/09 | 15:00-17:00 | Lab: [Fun Quiz](slides/Lab-fun-quiz.pdf); C++ templates and operator overloading [Demo](HelperCode/Demo-C++/) | help with weekly |
| 09/09 | 10:00-12:00 | [In-Order Pipelines (HWD)](slides/L3-InOrderPipe.pdf)| Chapter 3 of "Parallel Computer Organization and Design" Book |
| 09/09 | 13:00-15:00 | Lab: [Reduce and Scan in Cuda](slides/Lab-RedScan.pdf) | discussing second weekly, helping with the first |
| 09/09 | some time   | [**Assignment 2 handout**](weeklies/assignment-2/) | |
| 14/09 | 13:00-15:00 | [In-Order Pipelines (HWD)](slides/L3-InOrderPipe.pdf), [Optimizing ILP, VLIW Architectures (SFT-HWD)](slides/L4-VLIW.pdf) | Chapter 3 of "Parallel Computer Organization and Design" Book |
| 14/09 | 15:00-17:00 | Lab: [GPU hardware: three important design choices.](slides/Lab-GPU-HWD.pdf) | helping with weeklies |
| 16/09 | 10:00-12:00 | [Dependency Analysis of Imperative Loops](slides/L5-LoopParI.pdf) | Chapter 5 of lecture Notes |
| 16/09 | 13:00-15:00 |  | helping with the first two weekly assignments.
| 16/09 |  | No new weekly assignment this week; the third will be published next week | |
| 21/09 | 13:00-15:00 | [Demonstrating Simple Techniques for Optimizing Locality](slides/L6-locality.pdf) | Chapter 5 and 6 of Lecture Notes |
| 21/09 | 15:00-17:00 | [**Assignment 3+4 handout**](weeklies/assignment-3-4/) | helping with the weekly assignments. |
| 23/09 | 10:00-12:00 | [Optimizing Locality Continuation](slides/L6-locality.pdf); [Optimizing Locality same idea in other words: Nearest Neighbor, and again Matrix Multiplication and Transposition](slides/L5-LoopParI.pdf) | Chapters 5 and 6 of lecture Notes |
| 23/09 | 13:00-15:00 | Lab: discussing the third assignment | helping with the weekly assignments.
| 28/09 | 13:00-15:00 | HWD: [Memory Hierarchy, Bus-Based Coherency Protocols (HWD)](slides/L7-MemIntro.pdf)  | Chapter 4 and 5 of "Parallel Computer Organization and Design" Book
| 28/09 | 15:00-17:00 | Lab: [**Presenting Possible Group Projects**](group-projects/) | discussing group projects, helping with weekly assignments |
| 30/09 | 10:00-12:00 | HWD: [Bus-Based Coherency Protocols](slides/L7-MemIntro.pdf), and [Scalable Coherence Protocols](slides/L8-Interconnect.pdf) | Chapters 5 and 6 of "Parallel Computer Organization and Design" Book |
| 30/09 | 13:00-15:00 | Lab: [**Presenting Possible Group Projects**](group-projects/) | helping with weekly assignments, discussing group projects.
| 05/10 | 13:00-15:00 | HWD: [Scalable Coherence Protocols, Scalable Interconect (HWD)](slides/L8-Interconnect.pdf); if time permits [Exercises related to cache coherency and interconnect](hwd-exercises/hwd-coherence-in-exercises.pdf) | Chapters 5 and 6 of "Parallel Computer Organization and Design" Book |
| 05/10 | 15:00-17:00 | Lab: helping with weekly assignments and project |  |
| 07/10 | 10:00-12:00 | Lecture: [Demonstrating by Exercises the Coherency Protocols and Interconnect material](hwd-exercises/hwd-coherence-in-exercises.pdf) |  |
| 07/10 | 13:00-15:00 | | helping with weeklies and project
| 12/10 | 13:00-15:00 | Autumn break (no lecture) | |
| 12/10 | 15:00-17:00 | Autumn break (no lab) | |
| 14/10 | 10:00-12:00 | Autumn break (no lecture) | |
| 14/10 | 13:00-15:00 | Autumn break (no lab) |
| 19/10 | 13:00-15:00 | Lecture: helping with assignments (no lecture) |   |
| 19/10 | 15:00-17:00 | Lab: Helping with group project and weeklies | |
| 21/10 | 10:00-12:00 | [Inspector-Executor Techniques for Locality Optimizations (SFT)](slides/L9-LocOfRef.pdf) | [Facultative reading: various scientific papers](facultative-material/Opt-Loc-Ref) |
| 21/10 | 13:00-15:00 | Lab: help with group project, weeklies |
| 26/10 | 13:00-15:00 | Lecture: helping with group project and weeklies + Discussing student evaluations | you may read Tomasulo Algorithm (HWD) from Chapter 3 of "Parallel Computer Organization and Design" Book; [also on slides](slides/L10-OoOproc.pdf) |
| 26/10 | 15:00-17:00 | Lab: Helping with group project, weeklies | |
| 28/10 | 10:00-12:00 | Lecture: helping with group project | |
| 28/10 | 13:00-15:00 | Lab: help with group project |
| 03/11 |             | Assignment 5 Submission Deadline |
| 05/11 |             | Assignment 6 Submission Deadline |

## Assignments

**All submissions and resubmissions are to be made on Absalon!**

All assignments are individual in the sense that each student has to fully 
understand all aspects of the solution (which includes the submitted code)
and the report should include personal reflections on the handed-in solution.

However, some assignments can be solved by a group of students, as detailed
in the itemized list below, and the report should document the name of the
student who wrote a specific section/part of the report. Of course, all
group members should have roughly equal contributions to the solution and
report writing.
If there is disagreement within a group, you may duplicate disputed sections
to have different content, while documenting the name of the authors.

* Assignment 1 (10 points): published as late as Wednesday of the first week
     and requires fully individual solutions and report.

* Assignment 2 (15 points): published as late as Wednesday of the first week
     and requires fully individual solutions and report.

* Assignment 3 (10 points) and 4 (15 points) are to be solved in groups of two.
  Both have the same hand-in and hand-out date, as detailed later, since they
  have a common theme: optimizing locality of reference. Probably published
  on Monday of the fourth week.

* Assignment 5 (25 points) and 6 (25 points) are to be solved in groups of up to
    3 or 4 students, roughly during the last month of the course.
    They essentially consists of a larger project, in which Assignment 5 refers to
    submitting the code solution, and Assignment 6 refers to submitting the report.
    This intends to stress that the quality of the report will be reflected in
    the final grade. Meaning: if the report is poor, you will loose points.
    It also stands to reason that the quality of the report is tightly
    related to the quality of the solution (implementation), i.e., if the solution
    is not up to the standards, the report is bound to suffer as well.

* There will be no oral presentation of the "group" project (i.e., Assignment 5 & 6),
    because the number of enrolled students has grown and it is not practical anymore.

For more information, please see the course schedule and the sections below.

### Submission and Resubmission of Assignments

One resubmission attempt is granted for assignments 1-4, and the
resubmission attempt may be used to solve tasks missing in the original
hand-in and/or to improve on the existing hand-in. Resubmissions must
be submitted within a week since you have received the feedback for the
corresponding assignment. Please note that the first upload made on Absalon
*after* the original hand-in deadline will be considered as the resubmission hand-in!

The TAs will strive to provide feedback within 1.5 weeks of the submission 
deadline. Extensions may be granted on weekly assignment (re-)submission deadlines --
please ask the TAs if for any reason, personal or otherwise, you need an extension
(no need to involve Cosmin unless you wish to complain about the TAs decisions).

For Assignments 5 and 6, no resubmission is possible, since the deadlines are
just before exam week (Assignment 5) and within the exam week (Assignment 6).

### Assignment 1 (due September 10th)

* [Assignment text](weeklies/assignment-1/assignment1.asciidoc)
* [Code handin](weeklies/assignment-1/w1-code-handin.tar.gz)

### Assignment 2 (due September 22nd)

* [Assignment text](weeklies/assignment-2/assignment2.asciidoc)
* [Code handout](weeklies/assignment-2/w2-code-handin.tar.gz)

### Assignments 3+4 (due October 6th) -- this is a bigger assignment counting as two assignments

* [Assignment text](weeklies/assignment-3-4/assignment3-4.asciidoc)
* [Code handout](weeklies/assignment-3-4/w3-code-handin.tar.gz)


## Assignment 5 + 6 (Group project) tentatively due on 2nd and 5th of November, respsectivelly

Several potential choices for group project may be found in folder `group-projects`, namely

* **You are free to propose your own project, for example from the machine learning field, but please discuss it first with Cosmin, to make sure it is a relevant project, i.e., on which you can apply some of the techniques/reasoning that we have studied in PMPH.**
* [Single Pass Scan in Cuda (basic block of parallel programming)](group-projects/single-pass-scan)
* [Futhark or Cuda implementation for the Rank-K Search Problem](group-projects/rank-search-k)
* [Fast Sorting Algorithm(s) for GPUs](group-projects/sorting-on-gpu)
* [Fusing stencil computations (Halide)](group-projects/Halide)

Other projects, for which we do not provide a lot of guidance, may possibly be:
* [HP Implementation for Fusing Tensor Contractions (Deep Learning)](group-projects/tensor-contraction): read the paper, implement the technique (some initial code is provided), and try to replicate the results of the paper. 
* Use the tensor-core support of NVIDIA GPUs to unlock the performance of matrix-multiplication-heavy algorithms, such as Flash Attention. Please talk with Cosmin if you chose this one.

[Here you can find the CUB library and a simple program that utilizes CUB to sort](group-projects/cub-code-radixsort)


## GPU + MultiCore Machines

All students will be provided individual accounts on a multi-core and GPGPU
machine that supports multi-core programming via C++/OpenMP and CUDA
programming.

The available machines are equipped with top-end A100 GPUs & two AMD EPYC 7352
24-Core CPUs (total 96 hardware threads). You should have access to these
machines from 1st of September.

More specifically, the GPUs are located on the Futhark servers,
<!-- (access to which is obtained via the Hendrix gateway; connection guide below), -->
which include:
`hendrixfut01fl` or `hendrixfut03fl` servers, each of which is equipped with an
NVIDIA A100 GPU, on which you can run CUDA programs; and `hendrixfut02fl`, which
has an AMD GPU and hence cannot run CUDA programs (but which can run OpenCL
binaries, e.g. compiled using Futhark).


### Basic Futhark server connection guide

This basic connection guide is subject to change and may contain errors or
have missing information. Please ask Cornelius/Mark if you have trouble logging
onto the servers, or Cosmin, if you suspect the problem is an access/permission issue.

<!--  For more comprehensive info on the Hendrix cluster and how to connect, please see [this](https://diku-dk.github.io/wiki/slurm-cluster). -->

#### Step 0 -- update ssh config (one-time, optional)

<!--  Add the Hendrix gateway server to your ssh config by appending below paragraph: -->

Add the Futhark server to your ssh config by appending the paragraph below

```
Host futhark03
    HostName hendrixfut03fl
    User <KU-id>
    StrictHostKeyChecking no
    CheckHostIP no
    UserKnownHostsFile=/dev/null
```

to your ssh config file, located in either `$HOME/.ssh/config` for Linux/MacOS,
or `C:/Users/<user>/.ssh/config` for Windows (note: a simple text file with no
file extension). Remember to replace `<KU-id>` in line 3 with your personal
KU-id.

You may add other such paragraphs for `hendrixfut01fl` and `hendrixfut02fl`.

#### Step 1 -- connect to KU-VPN

*Each time* you wish to SSH to the Hendrix cluster/gateway, you must first be
properly connected to KU-VPN. If you get a "Name or service not known" error
from `ssh`, then you are probably not connected to the VPN. See [this guide on
connecting to KU-VPN](https://github.com/diku-dk/howto/blob/main/vpn.md).

<!--

#### Step 2 -- connect to Hendrix gateway

If you updated your ssh config as per step 0 and are properly connected to
KU-VPN, you may SSH to the Hendrix gateway using:

```bash
$ ssh hendrix
```

If you skipped step 0, you may need to manually supply appropriate flags to
`ssh` on each login.

##### Step 2b -- setup CUDA dev environment (one-time). Cosmin thinks that this step is NOT NEEDED!

The **first time** you log onto the Hendrix gateway, you must setup the CUDA dev
environment. To do so, permanently update your path by appending below snippet
to your `$HOME/.bash_profile` and/or `$HOME/.bashrc` files:

```bash
export CPATH=/usr/local/cuda/include:$CPATH
export LIBRARY_PATH=/usr/local/cuda/lib64:$LIBRARY_PATH
export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH
export PATH=/usr/local/cuda/bin:$PATH
```

Finally, reload the affected file/s using `source $HOME/.bash_profile`
and/or `source $HOME/.bashrc` (or simply starting a new bash session).

#### Step 3 -- connect to Futhark machine on the Hendrix cluster

From the Hendrix gateway shell, you may log further onto one of the Futhark
machines using e.g.:

```bash
$ ssh hendrixfut03fl
```

-->

#### Step 2 -- connect to Futhark machine on the Hendrix cluster

If you updated your ssh config as per step 0 and are properly connected to
KU-VPN, you may SSH to the futhark machine using something like:

```bash
$ ssh futhark03
```

Once logged onto a Futhark server (e.g., `hendrixfut03fl`), you may need to
load CUDA and/or Futhark modules using:

```bash
$ module load cuda;
$ module load futhark;
```

Or you may add those at the end of `$HOME/.bash_profile` and/or `$HOME/.bashrc` so you do not have to perform them every time.


<!-- ##### Alternatively: upload slurm jobs for exclusive execution -->
<!--  -->
<!-- If you prefer (or need) limited-time exclusive access to a GPU -- rather than -->
<!-- logging directly onto a Futhark server along with fellow students -- then you -->
<!-- can submit Slurm jobs to a job queue from the Hendrix gateway(s). For a very -->
<!-- basic guide on Slurm usage, please see [this -->
<!-- guide](https://github.com/diku-dk/howto/blob/main/servers.md). -->
<!--  -->
<!-- Note that using Slurm can be tedious at first, and you risk suspension of your -->
<!-- access if you abuse the queue system, so use at your own caution. -->


## Other resources

### Futhark and CUDA

* We will use a basic subset of Futhark during the course. Futhark related documentation can be found at [Futhark's webpage](https://futhark-lang.org), in particular a [tutorial](https://futhark-book.readthedocs.io/en/latest/) and [user guide](https://futhark.readthedocs.io/en/stable/)

* [CUDA C Best Practices Guide](https://docs.nvidia.com/cuda/cuda-c-best-practices-guide/index.html) you may want to browse through this guide to see what offers. No need to read all of it closely.


### Other Related Books

* Some of the compiler transformations taught in the software track can be found
in this book [Optimizing Compilers for Modern Architectures. Randy Allen and Ken Kennedy, Morgan Kaufmann, 2001](https://www.elsevier.com/books/optimizing-compilers-for-modern-architectures/allen/978-0-08-051324-9), but you are not expected to buy it or read for the purpose of PMPH.

* Similarly, some course topics are further developed in this book [High-Performance Computing Paradigm and Infrastructure](https://www.wiley.com/en-dk/High+Performance+Computing%3A+Paradigm+and+Infrastructure-p-9780471732709), e.g., Chapters 3, 8 and 11, but again, you are not expected to buy it or read for the purpose of PMPH.

