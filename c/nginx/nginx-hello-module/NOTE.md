# Notes from debugging hello module

1. Stack frames:

```
0  ngx_http_hello_handler (r=0x6eaab0) at /home/mm/workspace/learning/c/nginx/nginx-hello-module/ngx_http_hello_module.c:116
1  ngx_http_core_content_phase (r=0x6eaab0, ph=0x702f20)at src/http/ngx_http_core_module.c:1408
2  ngx_http_core_run_phases (r=0x6eaab0) at src/http/ngx_http_core_module.c:888
3  ngx_http_handler (r=0x6eaab0) at src/http/ngx_http_core_module.c:871
4  ngx_http_process_request (r=0x6eaab0) at src/http/ngx_http_request.c:1851
5  ngx_http_process_request_headers (rev=0x7037b8) at src/http/ngx_http_request.c:1282
6  ngx_http_process_request_line (rev=0x7037b8) at src/http/ngx_http_request.c:963
7  ngx_http_wait_request_handler (rev=0x7037b8) at src/http/ngx_http_request.c:486
8  ngx_epoll_process_events (cycle=0x6e5290, timer=59992, flags=1) at src/event/modules/ngx_epoll_module.c:683
9  ngx_process_events_and_timers (cycle=0x6e5290) at src/event/ngx_event.c:249
10 ngx_single_process_cycle (cycle=0x6e5290) at src/os/unix/ngx_process_cycle.c:315
11 main (argc=1, argv=0x7fffffffd088) at src/core/nginx.c:409
```

2. In `ngx_single_process_cycle` there are processes to init modules:

```c
for (i = 0; ngx_modules[i]; i++) {
    if (ngx_modules[i]->init_process) {
        if (ngx_modules[i]->init_process(cycle) == NGX_ERROR){
            /* fatal */
            exit(2);
        }
    }
}
```
