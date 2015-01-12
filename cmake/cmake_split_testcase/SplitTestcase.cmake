set (VAR "if(${info} MATCHES INFO:compiler([^]\"*)  ;myfoo;mybar")
foreach (ITEM ${VAR})
    message (${ITEM})
endforeach ()
