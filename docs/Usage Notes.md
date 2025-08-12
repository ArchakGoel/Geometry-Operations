# Usage Notes

1. Precision is borrowed from PRECISION.hxx in occt. Very good description.

## JSONS

1. There are different type of tasks configured to run and build main and other executables. All in tasks.json.
   1. For building main.
   2. To clear the build
   3. For debugging the main with a fresh build
   4. For debugging without fresh build
   5. For running the main - no debug and build.

2. For Tests the setup is:
   1. "Debug test (from root)" Use this for hitting breakpoints. 
      1. It is in Geometry Operations/.vscode launch.json and not in Tests/.vscode. Because from Tests, probably due to conflicting workspaces internally in lldb or VSCode, its not stopping at breakpoints.
      2. args is commented out in json, just put the name of the individual test you want to run.
      3. Launch it from main.cpp ->F5 -> select the option
   2. Build Tests and Clear Test Build are put in tasks.json under `Tests/.vscode`. Its a multi-root workspace setup as of now detailed by `geometry-operations.code-workspace`. Both Tests and main have separate roots.This remains to be solved, if this can be ignored and all tasks be put in the same root of main. That can get very cluttered with addition of more tests.

## Build Structure

   1. There are two executables right now, both - Tests and main both build under `Geometry Operations/build` folder.
   2. main builds at `build/MainBuild/main`.
   3. Tests for example, LineIntersectionTests build at `build/Tests/GeometryOperations/geomUtilsTests` 
   4. Both of the above are put in separate sub-folders so that when clear build is needed, that sub-folder is cleared separately without clear for main and Tests overlapping with each other.
   5. It remains to be figured out - the naming and folder structure for other test classes.

Run F5 or Debug/Run > icon and select the desired task. Or find from Shift+Comd+P ->Run Task -> Select the task.