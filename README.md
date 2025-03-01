The automatic domain decomposition logic has selected the MESH domain
 decomposition method with 4 processes per solution.

 *****  MAPDL SOLVE    COMMAND  *****

 *** NOTE ***                            CP =       6.250   TIME= 13:35:12
 There is no title defined for this analysis.

                       S O L U T I O N   O P T I O N S

   PROBLEM DIMENSIONALITY. . . . . . . . . . . . .3-D
   DEGREES OF FREEDOM. . . . . . UX   UY   UZ
   ANALYSIS TYPE . . . . . . . . . . . . . . . . .STATIC (STEADY-STATE)
   GLOBALLY ASSEMBLED MATRIX . . . . . . . . . . .SYMMETRIC

 *** NOTE ***                            CP =       6.250   TIME= 13:35:12
 Present time 0 is less than or equal to the previous time.  Time will
 default to 1.

 *** NOTE ***                            CP =       6.250   TIME= 13:35:12
 The conditions for direct assembly have been met.  No .emat or .erot
 files will be produced.

 *** NOTE ***                            CP =       6.250   TIME= 13:35:12
 The number of distributed memory parallel processes specified is
 greater than the number of elements selected in the model.  The number
 of distributed memory parallel processes will be reduced to 1 for this
 solution.

                      L O A D   S T E P   O P T I O N S

   LOAD STEP NUMBER. . . . . . . . . . . . . . . .     1
   TIME AT END OF THE LOAD STEP. . . . . . . . . .  1.0000
   NUMBER OF SUBSTEPS. . . . . . . . . . . . . . .     1
   STEP CHANGE BOUNDARY CONDITIONS . . . . . . . .    NO
   PRINT OUTPUT CONTROLS . . . . . . . . . . . . .NO PRINTOUT
   DATABASE OUTPUT CONTROLS. . . . . . . . . . . .ALL DATA WRITTEN
                                                  FOR THE LAST SUBSTEP


 SOLUTION MONITORING INFO IS WRITTEN TO FILE= file.mntr                                                                             


 THE BELOW ELEMENT MATRICES AND LOAD VECTORS ARE IN THE NODAL COORDINATE SYSTEMS.
 GRAVITY AND TRANSIENT EFFECTS ARE INCLUDED.

      STIFFNESS MATRIX FOR ELEMENT        1          LINK180
   1   0.2100000E+05  0.0000000E+00  0.0000000E+00 -0.2100000E+05  0.0000000E+00  0.0000000E+00
   2   0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00
   3   0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00
   4  -0.2100000E+05  0.0000000E+00  0.0000000E+00  0.2100000E+05  0.0000000E+00  0.0000000E+00
   5   0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00
   6   0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00  0.0000000E+00

 Range of element maximum matrix coefficients in global coordinates
 Maximum = 21000 at element 1.
 Minimum = 21000 at element 1.

   *** ELEMENT MATRIX FORMULATION TIMES
     TYPE    NUMBER   ENAME      TOTAL CP  AVE CP

        1         1  LINK180       0.000   0.000000
 Time at end of element matrix formulation CP = 6.296875.

 SPARSE MATRIX DIRECT SOLVER.
  Number of equations =           2,    Maximum wavefront =      6


  Memory allocated on this process
  -------------------------------------------------------------------
  Equation solver memory allocated                     =     0.061 MB
  Equation solver memory required for in-core mode     =     0.058 MB
  Equation solver memory required for out-of-core mode =     0.050 MB
  Total (solver and non-solver) memory allocated       =   388.107 MB

 *** NOTE ***                            CP =       6.297   TIME= 13:35:12
 The Sparse Matrix Solver is currently running in the in-core memory
 mode.  This memory mode uses the most amount of memory in order to
 avoid using the hard drive as much as possible, which most often
 results in the fastest solution time.  This mode is recommended if
 enough physical memory is present to accommodate all of the solver
 data.
 Sparse solver maximum pivot= 21000 at node 1 UX.
 Sparse solver minimum pivot= 0 at node 2 UX.
 Sparse solver minimum pivot in absolute value= 0 at node 2 UX.

 *** ERROR ***                           CP =       6.297   TIME= 13:35:12
 There are 1 small equation solver pivot terms (e.g., at the UX degree
 of freedom of node 2).  Please check for an insufficiently constrained
 model.
 One-Dimensional Bar Element Stiffness Matrix Analysis Using ANSYS.
