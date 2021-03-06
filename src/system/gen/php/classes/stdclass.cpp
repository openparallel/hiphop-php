/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010 Facebook, Inc. (http://www.facebook.com)          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
// @generated by HipHop Compiler

#include <php/classes/stdclass.h>
#include <runtime/ext/ext.h>
#include <runtime/eval/eval.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
/* preface finishes */
/* SRC: classes/stdclass.php line 4 */
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_GETINIT_stdclass
Variant c_stdclass::os_getInit(const char *s, int64 hash) {
  return c_ObjectData::os_getInit(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_GETINIT_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_GET_stdclass
Variant c_stdclass::os_get(const char *s, int64 hash) {
  return c_ObjectData::os_get(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_GET_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_LVAL_stdclass
Variant &c_stdclass::os_lval(const char *s, int64 hash) {
  return c_ObjectData::os_lval(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_LVAL_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_GETARRAY_stdclass
void c_stdclass::o_get(Array &props) const {
  c_ObjectData::o_get(props);
}
#endif // OMIT_JUMP_TABLE_CLASS_GETARRAY_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_get_stdclass
Variant c_stdclass::o_get(CStrRef prop, int64 phash, bool error /* = true */, const char *context /* = NULL */) {
  return c_stdclass::o_getPublic(prop, phash, error);
}
#endif // OMIT_JUMP_TABLE_CLASS_get_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_get_PUBLIC_stdclass
Variant c_stdclass::o_getPublic(CStrRef s, int64 hash, bool error /* = true */) {
  return c_ObjectData::o_getPublic(s, hash, error);
}
#endif // OMIT_JUMP_TABLE_CLASS_get_PUBLIC_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_get_PRIVATE_stdclass
Variant c_stdclass::o_getPrivate(CStrRef s, int64 hash, bool error /* = true */) {
  return o_getPublic(s, hash, error);
}
#endif // OMIT_JUMP_TABLE_CLASS_get_PRIVATE_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_exists_stdclass
bool c_stdclass::o_exists(CStrRef prop, int64 phash, const char *context /* = NULL */) const {
  return c_stdclass::o_existsPublic(prop, phash);
}
#endif // OMIT_JUMP_TABLE_CLASS_exists_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_exists_PUBLIC_stdclass
bool c_stdclass::o_existsPublic(CStrRef s, int64 hash) const {
  return c_ObjectData::o_existsPublic(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_exists_PUBLIC_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_exists_PRIVATE_stdclass
bool c_stdclass::o_existsPrivate(CStrRef s, int64 hash) const {
  return o_existsPublic(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_exists_PRIVATE_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_set_stdclass
Variant c_stdclass::o_set(CStrRef prop, int64 phash, CVarRef v, bool forInit /* = false */, const char *context /* = NULL */) {
  return c_stdclass::o_setPublic(prop, phash, v, forInit);
}
#endif // OMIT_JUMP_TABLE_CLASS_set_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_set_PUBLIC_stdclass
Variant c_stdclass::o_setPublic(CStrRef s, int64 hash, CVarRef v, bool forInit /* = false */) {
  return c_ObjectData::o_setPublic(s, hash, v, forInit);
}
#endif // OMIT_JUMP_TABLE_CLASS_set_PUBLIC_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_set_PRIVATE_stdclass
Variant c_stdclass::o_setPrivate(CStrRef s, int64 hash, CVarRef v, bool forInit /* = false */) {
  return o_setPublic(s, hash, v, forInit);
}
#endif // OMIT_JUMP_TABLE_CLASS_set_PRIVATE_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_lval_stdclass
Variant& c_stdclass::o_lval(CStrRef prop, int64 phash, const char *context /* = NULL */) {
  return c_stdclass::o_lvalPublic(prop, phash);
}
#endif // OMIT_JUMP_TABLE_CLASS_lval_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_lval_PUBLIC_stdclass
Variant& c_stdclass::o_lvalPublic(CStrRef s, int64 hash) {
  return c_ObjectData::o_lvalPublic(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_lval_PUBLIC_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_lval_PRIVATE_stdclass
Variant& c_stdclass::o_lvalPrivate(CStrRef s, int64 hash) {
  return o_lvalPublic(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_lval_PRIVATE_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_CONSTANT_stdclass
Variant c_stdclass::os_constant(const char *s) {
  return c_ObjectData::os_constant(s);
}
#endif // OMIT_JUMP_TABLE_CLASS_CONSTANT_stdclass
IMPLEMENT_CLASS(stdclass)
ObjectData *c_stdclass::cloneImpl() {
  c_stdclass *obj = NEW(c_stdclass)();
  cloneSet(obj);
  return obj;
}
void c_stdclass::cloneSet(c_stdclass *clone) {
  ObjectData::cloneSet(clone);
}
#ifndef OMIT_JUMP_TABLE_CLASS_INVOKE_stdclass
Variant c_stdclass::o_invoke(const char *s, CArrRef params, int64 hash, bool fatal) {
  int count __attribute__((__unused__)) = params.size();
  return c_ObjectData::o_invoke(s, params, hash, fatal);
}
#endif // OMIT_JUMP_TABLE_CLASS_INVOKE_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_INVOKE_stdclass
Variant c_stdclass::o_invoke_few_args(const char *s, int64 hash, int count, CVarRef a0, CVarRef a1, CVarRef a2, CVarRef a3, CVarRef a4, CVarRef a5) {
  return c_ObjectData::o_invoke_few_args(s, hash, count, a0, a1, a2, a3, a4, a5);
}
#endif // OMIT_JUMP_TABLE_CLASS_INVOKE_stdclass
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_INVOKE_stdclass
Variant c_stdclass::os_invoke(const char *c, const char *s, CArrRef params, int64 hash, bool fatal) {
  int count __attribute__((__unused__)) = params.size();
  return c_ObjectData::os_invoke(c, s, params, hash, fatal);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_INVOKE_stdclass
Variant c_stdclass::o_invoke_from_eval(const char *s, Eval::VariableEnvironment &env, const Eval::FunctionCallExpression *caller, int64 hash, bool fatal) {
  return c_ObjectData::o_invoke_from_eval(s, env, caller, hash, fatal);
}
Variant c_stdclass::os_invoke_from_eval(const char *c, const char *s, Eval::VariableEnvironment &env, const Eval::FunctionCallExpression *caller, int64 hash, bool fatal) {
  return c_ObjectData::os_invoke_from_eval(c, s, env, caller, hash, fatal);
}
struct ObjectStaticCallbacks cw_stdclass = {
  c_stdclass::os_getInit,
  c_stdclass::os_get,
  c_stdclass::os_lval,
  c_stdclass::os_invoke,
  c_stdclass::os_constant,
};
void c_stdclass::init() {
}
/* SRC: classes/stdclass.php line 8 */
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_GETINIT___php_incomplete_class
Variant c___php_incomplete_class::os_getInit(const char *s, int64 hash) {
  return c_ObjectData::os_getInit(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_GETINIT___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_GET___php_incomplete_class
Variant c___php_incomplete_class::os_get(const char *s, int64 hash) {
  return c_ObjectData::os_get(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_GET___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_LVAL___php_incomplete_class
Variant &c___php_incomplete_class::os_lval(const char *s, int64 hash) {
  return c_ObjectData::os_lval(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_LVAL___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_GETARRAY___php_incomplete_class
void c___php_incomplete_class::o_get(Array &props) const {
  c_ObjectData::o_get(props);
}
#endif // OMIT_JUMP_TABLE_CLASS_GETARRAY___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_get___php_incomplete_class
Variant c___php_incomplete_class::o_get(CStrRef prop, int64 phash, bool error /* = true */, const char *context /* = NULL */) {
  return c___php_incomplete_class::o_getPublic(prop, phash, error);
}
#endif // OMIT_JUMP_TABLE_CLASS_get___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_get_PUBLIC___php_incomplete_class
Variant c___php_incomplete_class::o_getPublic(CStrRef s, int64 hash, bool error /* = true */) {
  return c_ObjectData::o_getPublic(s, hash, error);
}
#endif // OMIT_JUMP_TABLE_CLASS_get_PUBLIC___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_get_PRIVATE___php_incomplete_class
Variant c___php_incomplete_class::o_getPrivate(CStrRef s, int64 hash, bool error /* = true */) {
  return o_getPublic(s, hash, error);
}
#endif // OMIT_JUMP_TABLE_CLASS_get_PRIVATE___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_exists___php_incomplete_class
bool c___php_incomplete_class::o_exists(CStrRef prop, int64 phash, const char *context /* = NULL */) const {
  return c___php_incomplete_class::o_existsPublic(prop, phash);
}
#endif // OMIT_JUMP_TABLE_CLASS_exists___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_exists_PUBLIC___php_incomplete_class
bool c___php_incomplete_class::o_existsPublic(CStrRef s, int64 hash) const {
  return c_ObjectData::o_existsPublic(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_exists_PUBLIC___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_exists_PRIVATE___php_incomplete_class
bool c___php_incomplete_class::o_existsPrivate(CStrRef s, int64 hash) const {
  return o_existsPublic(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_exists_PRIVATE___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_set___php_incomplete_class
Variant c___php_incomplete_class::o_set(CStrRef prop, int64 phash, CVarRef v, bool forInit /* = false */, const char *context /* = NULL */) {
  return c___php_incomplete_class::o_setPublic(prop, phash, v, forInit);
}
#endif // OMIT_JUMP_TABLE_CLASS_set___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_set_PUBLIC___php_incomplete_class
Variant c___php_incomplete_class::o_setPublic(CStrRef s, int64 hash, CVarRef v, bool forInit /* = false */) {
  return c_ObjectData::o_setPublic(s, hash, v, forInit);
}
#endif // OMIT_JUMP_TABLE_CLASS_set_PUBLIC___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_set_PRIVATE___php_incomplete_class
Variant c___php_incomplete_class::o_setPrivate(CStrRef s, int64 hash, CVarRef v, bool forInit /* = false */) {
  return o_setPublic(s, hash, v, forInit);
}
#endif // OMIT_JUMP_TABLE_CLASS_set_PRIVATE___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_lval___php_incomplete_class
Variant& c___php_incomplete_class::o_lval(CStrRef prop, int64 phash, const char *context /* = NULL */) {
  return c___php_incomplete_class::o_lvalPublic(prop, phash);
}
#endif // OMIT_JUMP_TABLE_CLASS_lval___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_lval_PUBLIC___php_incomplete_class
Variant& c___php_incomplete_class::o_lvalPublic(CStrRef s, int64 hash) {
  return c_ObjectData::o_lvalPublic(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_lval_PUBLIC___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_lval_PRIVATE___php_incomplete_class
Variant& c___php_incomplete_class::o_lvalPrivate(CStrRef s, int64 hash) {
  return o_lvalPublic(s, hash);
}
#endif // OMIT_JUMP_TABLE_CLASS_lval_PRIVATE___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_CONSTANT___php_incomplete_class
Variant c___php_incomplete_class::os_constant(const char *s) {
  return c_ObjectData::os_constant(s);
}
#endif // OMIT_JUMP_TABLE_CLASS_CONSTANT___php_incomplete_class
IMPLEMENT_CLASS(__php_incomplete_class)
ObjectData *c___php_incomplete_class::cloneImpl() {
  c___php_incomplete_class *obj = NEW(c___php_incomplete_class)();
  cloneSet(obj);
  return obj;
}
void c___php_incomplete_class::cloneSet(c___php_incomplete_class *clone) {
  ObjectData::cloneSet(clone);
}
#ifndef OMIT_JUMP_TABLE_CLASS_INVOKE___php_incomplete_class
Variant c___php_incomplete_class::o_invoke(const char *s, CArrRef params, int64 hash, bool fatal) {
  int count __attribute__((__unused__)) = params.size();
  return c_ObjectData::o_invoke(s, params, hash, fatal);
}
#endif // OMIT_JUMP_TABLE_CLASS_INVOKE___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_INVOKE___php_incomplete_class
Variant c___php_incomplete_class::o_invoke_few_args(const char *s, int64 hash, int count, CVarRef a0, CVarRef a1, CVarRef a2, CVarRef a3, CVarRef a4, CVarRef a5) {
  return c_ObjectData::o_invoke_few_args(s, hash, count, a0, a1, a2, a3, a4, a5);
}
#endif // OMIT_JUMP_TABLE_CLASS_INVOKE___php_incomplete_class
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_INVOKE___php_incomplete_class
Variant c___php_incomplete_class::os_invoke(const char *c, const char *s, CArrRef params, int64 hash, bool fatal) {
  int count __attribute__((__unused__)) = params.size();
  return c_ObjectData::os_invoke(c, s, params, hash, fatal);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_INVOKE___php_incomplete_class
Variant c___php_incomplete_class::o_invoke_from_eval(const char *s, Eval::VariableEnvironment &env, const Eval::FunctionCallExpression *caller, int64 hash, bool fatal) {
  return c_ObjectData::o_invoke_from_eval(s, env, caller, hash, fatal);
}
Variant c___php_incomplete_class::os_invoke_from_eval(const char *c, const char *s, Eval::VariableEnvironment &env, const Eval::FunctionCallExpression *caller, int64 hash, bool fatal) {
  return c_ObjectData::os_invoke_from_eval(c, s, env, caller, hash, fatal);
}
struct ObjectStaticCallbacks cw___php_incomplete_class = {
  c___php_incomplete_class::os_getInit,
  c___php_incomplete_class::os_get,
  c___php_incomplete_class::os_lval,
  c___php_incomplete_class::os_invoke,
  c___php_incomplete_class::os_constant,
};
void c___php_incomplete_class::init() {
}
Object co_stdclass(CArrRef params, bool init /* = true */) {
  return Object((NEW(c_stdclass)())->dynCreate(params, init));
}
Object co___php_incomplete_class(CArrRef params, bool init /* = true */) {
  return Object((NEW(c___php_incomplete_class)())->dynCreate(params, init));
}
Variant pm_php$classes$stdclass_php(bool incOnce /* = false */, LVariableTable* variables /* = NULL */) {
  {
    DECLARE_SYSTEM_GLOBALS(g);
    bool &alreadyRun = g->run_pm_php$classes$stdclass_php;
    if (alreadyRun) { if (incOnce) return true;}
    else alreadyRun = true;
    if (!variables) variables = g;
  }
  PSEUDOMAIN_INJECTION(run_init::classes/stdclass.php);
  DECLARE_SYSTEM_GLOBALS(g);
  LVariableTable *gVariables __attribute__((__unused__)) = get_variable_table();
  return true;
} /* function */

///////////////////////////////////////////////////////////////////////////////
}
