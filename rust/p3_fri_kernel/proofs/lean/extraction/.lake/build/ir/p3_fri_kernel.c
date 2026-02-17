// Lean compiler output
// Module: p3_fri_kernel
// Imports: public import Init public import Hax public import Std.Tactic.Do public import Std.Do.Triple public import Std.Tactic.Do.Syntax public import CoreModelsPatch
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
LEAN_EXPORT lean_object* l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__5(lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_USize64_sub(lean_object*, lean_object*);
static lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__4___closed__0;
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__3(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_RustM_bind___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round(lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__0(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0___redArg(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; lean_object* x_5; 
x_3 = lean_nat_dec_lt(x_1, x_2);
x_4 = lean_box(x_3);
x_5 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_5, 0, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0___redArg(x_1, x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__0(lean_object* x_1, lean_object* x_2, uint8_t x_3) {
_start:
{
if (x_3 == 0)
{
lean_object* x_4; 
lean_dec(x_2);
x_4 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_4, 0, x_1);
return x_4;
}
else
{
lean_object* x_5; 
lean_dec(x_1);
x_5 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_5, 0, x_2);
return x_5;
}
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__1(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
lean_inc(x_2);
lean_inc(x_1);
x_3 = lean_alloc_closure((void*)(l_P3__fri__kernel_compute__log__arity__for__round___lam__0___boxed), 3, 2);
lean_closure_set(x_3, 0, x_1);
lean_closure_set(x_3, 1, x_2);
x_4 = l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0___redArg(x_2, x_1);
lean_dec(x_1);
lean_dec(x_2);
x_5 = l_RustM_bind___redArg(x_4, x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__2(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lean_apply_1(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__5(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, uint8_t x_5) {
_start:
{
if (x_5 == 0)
{
lean_object* x_6; lean_object* x_7; 
lean_dec_ref(x_4);
lean_dec(x_3);
x_6 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_6, 0, x_1);
x_7 = l_RustM_bind___redArg(x_6, x_2);
return x_7;
}
else
{
lean_object* x_8; lean_object* x_9; 
lean_dec_ref(x_2);
lean_dec(x_1);
x_8 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_8, 0, x_3);
x_9 = l_RustM_bind___redArg(x_8, x_4);
return x_9;
}
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__3(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; 
lean_inc(x_4);
lean_inc(x_1);
x_5 = lean_alloc_closure((void*)(l_P3__fri__kernel_compute__log__arity__for__round___lam__5___boxed), 5, 4);
lean_closure_set(x_5, 0, x_1);
lean_closure_set(x_5, 1, x_2);
lean_closure_set(x_5, 2, x_4);
lean_closure_set(x_5, 3, x_3);
x_6 = l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0___redArg(x_4, x_1);
lean_dec(x_1);
lean_dec(x_4);
x_7 = l_RustM_bind___redArg(x_6, x_5);
return x_7;
}
}
static lean_object* _init_l_P3__fri__kernel_compute__log__arity__for__round___lam__4___closed__0() {
_start:
{
uint8_t x_1; lean_object* x_2; 
x_1 = 1;
x_2 = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(x_2, 0, x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__4(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
uint8_t x_7; 
lean_dec_ref(x_5);
x_7 = !lean_is_exclusive(x_1);
if (x_7 == 0)
{
lean_object* x_8; lean_object* x_9; uint8_t x_10; 
x_8 = lean_ctor_get(x_1, 0);
x_9 = lean_alloc_closure((void*)(l_P3__fri__kernel_compute__log__arity__for__round___lam__3), 4, 3);
lean_closure_set(x_9, 0, x_6);
lean_closure_set(x_9, 1, x_2);
lean_closure_set(x_9, 2, x_3);
x_10 = lean_nat_dec_lt(x_4, x_8);
if (x_10 == 0)
{
lean_object* x_11; lean_object* x_12; 
x_11 = l_USize64_sub(x_4, x_8);
lean_dec(x_8);
lean_ctor_set(x_1, 0, x_11);
x_12 = l_RustM_bind___redArg(x_1, x_9);
return x_12;
}
else
{
lean_object* x_13; lean_object* x_14; 
lean_free_object(x_1);
lean_dec(x_8);
x_13 = l_P3__fri__kernel_compute__log__arity__for__round___lam__4___closed__0;
x_14 = l_RustM_bind___redArg(x_13, x_9);
return x_14;
}
}
else
{
lean_object* x_15; lean_object* x_16; uint8_t x_17; 
x_15 = lean_ctor_get(x_1, 0);
lean_inc(x_15);
lean_dec(x_1);
x_16 = lean_alloc_closure((void*)(l_P3__fri__kernel_compute__log__arity__for__round___lam__3), 4, 3);
lean_closure_set(x_16, 0, x_6);
lean_closure_set(x_16, 1, x_2);
lean_closure_set(x_16, 2, x_3);
x_17 = lean_nat_dec_lt(x_4, x_15);
if (x_17 == 0)
{
lean_object* x_18; lean_object* x_19; lean_object* x_20; 
x_18 = l_USize64_sub(x_4, x_15);
lean_dec(x_15);
x_19 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_19, 0, x_18);
x_20 = l_RustM_bind___redArg(x_19, x_16);
return x_20;
}
else
{
lean_object* x_21; lean_object* x_22; 
lean_dec(x_15);
x_21 = l_P3__fri__kernel_compute__log__arity__for__round___lam__4___closed__0;
x_22 = l_RustM_bind___redArg(x_21, x_16);
return x_22;
}
}
}
else
{
lean_object* x_23; lean_object* x_24; 
lean_dec_ref(x_3);
lean_dec_ref(x_2);
x_23 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_23, 0, x_6);
x_24 = l_RustM_bind___redArg(x_23, x_5);
return x_24;
}
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_5 = lean_alloc_closure((void*)(l_P3__fri__kernel_compute__log__arity__for__round___lam__1), 2, 1);
lean_closure_set(x_5, 0, x_4);
x_6 = lean_alloc_closure((void*)(l_P3__fri__kernel_compute__log__arity__for__round___lam__2), 2, 1);
lean_closure_set(x_6, 0, x_5);
lean_inc(x_1);
lean_inc_ref_n(x_6, 2);
x_7 = lean_alloc_closure((void*)(l_P3__fri__kernel_compute__log__arity__for__round___lam__4___boxed), 6, 5);
lean_closure_set(x_7, 0, x_2);
lean_closure_set(x_7, 1, x_6);
lean_closure_set(x_7, 2, x_6);
lean_closure_set(x_7, 3, x_1);
lean_closure_set(x_7, 4, x_6);
x_8 = lean_nat_dec_lt(x_1, x_3);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; 
x_9 = l_USize64_sub(x_1, x_3);
lean_dec(x_1);
x_10 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_10, 0, x_9);
x_11 = l_RustM_bind___redArg(x_10, x_7);
return x_11;
}
else
{
lean_object* x_12; lean_object* x_13; 
lean_dec(x_1);
x_12 = l_P3__fri__kernel_compute__log__arity__for__round___lam__4___closed__0;
x_13 = l_RustM_bind___redArg(x_12, x_7);
return x_13;
}
}
}
LEAN_EXPORT lean_object* l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0___redArg___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0___redArg(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_Rust__primitives_Hax_Machine__int_lt___at___00P3__fri__kernel_compute__log__arity__for__round_spec__0(x_1, x_2, x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
return x_5;
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__0___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_3);
x_5 = l_P3__fri__kernel_compute__log__arity__for__round___lam__0(x_1, x_2, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__5___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = lean_unbox(x_5);
x_7 = l_P3__fri__kernel_compute__log__arity__for__round___lam__5(x_1, x_2, x_3, x_4, x_6);
return x_7;
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___lam__4___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; 
x_7 = l_P3__fri__kernel_compute__log__arity__for__round___lam__4(x_1, x_2, x_3, x_4, x_5, x_6);
lean_dec(x_4);
return x_7;
}
}
LEAN_EXPORT lean_object* l_P3__fri__kernel_compute__log__arity__for__round___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_P3__fri__kernel_compute__log__arity__for__round(x_1, x_2, x_3, x_4);
lean_dec(x_3);
return x_5;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Hax(uint8_t builtin);
lean_object* initialize_Std_Tactic_Do(uint8_t builtin);
lean_object* initialize_Std_Do_Triple(uint8_t builtin);
lean_object* initialize_Std_Tactic_Do_Syntax(uint8_t builtin);
lean_object* initialize_CoreModelsPatch(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_p3__fri__kernel(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Hax(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Std_Tactic_Do(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Std_Do_Triple(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Std_Tactic_Do_Syntax(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_CoreModelsPatch(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_P3__fri__kernel_compute__log__arity__for__round___lam__4___closed__0 = _init_l_P3__fri__kernel_compute__log__arity__for__round___lam__4___closed__0();
lean_mark_persistent(l_P3__fri__kernel_compute__log__arity__for__round___lam__4___closed__0);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
