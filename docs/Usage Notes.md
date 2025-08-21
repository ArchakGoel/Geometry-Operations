# Usage Notes

## Workspace

1. Project is setup as a multi-root workspace setup as of now. Detailed by `geometry-operations.code-workspace`. So open the project as `Geometry Root` workspace. Both Tests and main have separate roots. This remains to be solved: a way to steer away from multi-root setup and put all tasks in the same root of main. That can get very cluttered with addition of more tests.

## JSONS

1. There are different type of tasks configured to run and build main and other executables. All in tasks.json.
   1. For building main.
   2. To clear the build
   3. For debugging the main with a fresh build
   4. For debugging without fresh build
   5. For running the main - no debug and build.

2. For Tests the setup is:
   1. "Debug test (from root)" Use this for debugging while hitting the breakpoints.
      1. It is in `Geometry Operations/.vscode/launch.json` and not in `Tests/.vscode/`. Because from Tests, probably due to conflicting workspaces internally in lldb or VSCode, its not working to stop at breakpoints.
      2. For running a specific test with breakpoints use the `Debug Specific Test` launch option in the same launch.json as 1.
      3. Launch it from main.cpp -> F5 -> select the launch option
   2. Build Tests and Clear Test Build are put in tasks.json under `Tests/.vscode`. 

## Build Structure

   1. There are two executables right now, both - Tests and main both build under `Geometry Operations/build` folder.
   2. main builds at `build/MainBuild/main`.
   3. Tests for example, LineIntersectionTests build at `build/Tests/GeometryOperations/geomUtilsTests` 
   4. Both of the above are put in separate sub-folders so that when clear build is needed, that sub-folder is cleared separately without clear for main and Tests overlapping with each other.
   5. It remains to be figured out - the naming and folder structure for other test classes.

Run F5 or Debug/Run > icon and select the desired task. Or find from Shift+Comd+P ->Run Task -> Select the task.