int x_global_uninit;

int x_global_init=1;

extern int x_global;

int fn_a(int x,int y);

int fn_b(int x_local){
    return fn_a(x_local,x_global_init);
}