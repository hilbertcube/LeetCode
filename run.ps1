param(
  [Parameter(Mandatory=$true)][string]$Name
)

# ensure bin/ exists
if (!(Test-Path -Path "bin")) {
  New-Item -ItemType Directory -Path "bin" | Out-Null
}

# compile
g++ "$Name.cpp" -o "bin\$Name.exe"
if ($LASTEXITCODE -ne 0) {
  Write-Error "Compilation failed (g++ exited with code $LASTEXITCODE)"
  exit $LASTEXITCODE
}

# run
& "bin\$Name.exe"