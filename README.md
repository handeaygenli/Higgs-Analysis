# Higgs-Analysis

In this study, a C language implementation of CompHep infrastructure was used to analyse the Higgs Boson. Kinematic distributions of jets, H boson and Z boson were studied. (p1p1->ZjHj1j1). This study requires the addition of model files to the Comphep infrastructure. First of all, the files (txt file) produced in CompHep were converted to "lhe" format. This "lhe" file, which was also created with the ExRootLHEFConverter command, was converted to "ROOT" format.

Using the command LHEF->MakeClass("HiggsAnalysis"), the C and Header file of the ROOT file were created. To perform the analysis, the following commands are applied after the desired analysis codes are written in the C file.

.L ZtoEeAnalysis.C

ZtoEeAnalysis t

t.Loop()

# Jet Distributions

![Screenshot (21)](https://user-images.githubusercontent.com/62266472/206789359-654d4474-a868-4b63-8208-7abe4a1696d4.png)

# Higss Boson and Z Boson Distributions

![Screenshot (20)](https://user-images.githubusercontent.com/62266472/206789337-bc5a1030-76f5-4d4b-90fa-58a09a5d240e.png)

# Higgs Boson and Z Boson Mass Distributions

![Screenshot (22)](https://user-images.githubusercontent.com/62266472/206789250-d1e1e291-170e-4b51-a83a-22c0e3f1b656.png)
