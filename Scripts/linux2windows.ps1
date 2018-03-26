(Get-Content "main.c") | Set-Content "main.c"
(Get-Content "main.c") | ForEach-Object { $_ -replace "clear", "cls" } | Set-Content "main.c"
(Get-Content "main.c") | ForEach-Object { $_ -replace "./db/", ".\\db\\" } | Set-Content "main.c"