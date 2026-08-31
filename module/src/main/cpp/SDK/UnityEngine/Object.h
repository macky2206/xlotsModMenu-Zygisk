#pragma once
#include "BNM/BNMIncludes.hpp"

namespace UnityEngine {
	class Object : public BNM::IL2CPP::Il2CppObject
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("UnityEngine", "Object", BNM::Image("UnityEngine.CoreModule.dll"));
		}
		
		/* @brief Orig Type: System.IntPtr */
		template <typename T = BNM::Types::nuint> T m_CachedPtr() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("m_CachedPtr");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.IntPtr */
		void set_m_CachedPtr(BNM::Types::nuint value) {
			static BNM::Field<BNM::Types::nuint> __bnm__field__ = StaticClass().GetField("m_CachedPtr");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> static T OffsetOfInstanceIDInCPlusPlusObject() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("OffsetOfInstanceIDInCPlusPlusObject");
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		static void set_OffsetOfInstanceIDInCPlusPlusObject(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("OffsetOfInstanceIDInCPlusPlusObject");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> static T objectIsNullMessage() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("objectIsNullMessage");
			return __bnm__field__();
		}
		/* @param value Orig Type: System.String */
		static void set_objectIsNullMessage(BNM::Structures::Mono::String* value) {
			static BNM::Field<BNM::Structures::Mono::String*> __bnm__field__ = StaticClass().GetField("objectIsNullMessage");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> static T cloneDestroyedMessage() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("cloneDestroyedMessage");
			return __bnm__field__();
		}
		/* @param value Orig Type: System.String */
		static void set_cloneDestroyedMessage(BNM::Structures::Mono::String* value) {
			static BNM::Field<BNM::Structures::Mono::String*> __bnm__field__ = StaticClass().GetField("cloneDestroyedMessage");
			__bnm__field__.Set(value);
		}
		
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T GetInstanceID() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("GetInstanceID", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T GetHashCode() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("GetHashCode", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> T Equals(BNM::IL2CPP::Il2CppObject* other) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Equals", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](other);
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> static T op_Implicit(UnityEngine::Object* exists) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("op_Implicit", 1);
			return __bnm__method__(exists);
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> static T CompareBaseObjects(UnityEngine::Object* lhs, UnityEngine::Object* rhs) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("CompareBaseObjects", 2);
			return __bnm__method__(lhs, rhs);
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> static T IsNativeObjectAlive(UnityEngine::Object* o) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("IsNativeObjectAlive", 1);
			return __bnm__method__(o);
		}
		/* @brief Orig Type: System.IntPtr */
		template <typename T = BNM::Types::nuint> T GetCachedPtr() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("GetCachedPtr", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T get_name() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("get_name", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T set_name(BNM::Structures::Mono::String* $value) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("set_name", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]($value);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T Instantiate(UnityEngine::Object* original, BNM::Structures::Unity::Vector3 position, BNM::Structures::Unity::Quaternion rotation) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Instantiate", 3);
			return __bnm__method__(original, position, rotation);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T Instantiate_1(UnityEngine::Object* original, BNM::Structures::Unity::Vector3 position, BNM::Structures::Unity::Quaternion rotation, BNM::IL2CPP::Il2CppObject* parent) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Instantiate", 4);
			return __bnm__method__(original, position, rotation, parent);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T Instantiate_2(UnityEngine::Object* original) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Instantiate", 1);
			return __bnm__method__(original);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T Instantiate_3(UnityEngine::Object* original, BNM::IL2CPP::Il2CppObject* parent, bool instantiateInWorldSpace) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Instantiate", 3);
			return __bnm__method__(original, parent, instantiateInWorldSpace);
		}
		/* @brief Orig Type: T */
		/* @brief Helper: call generic Instantiate<T>() by providing compile-time class(es) */
		template <typename T = void*> static T InstantiateGeneric(const BNM::CompileTimeClass &compileType0, void* original) {
			auto methodBase = StaticClass().GetMethod("Instantiate", 1);
			auto genericMethod = methodBase.GetGeneric({compileType0});
			if (!genericMethod.IsValid()) return (T)nullptr;
			BNM::Method<T> typedMethod = genericMethod;
			if (!typedMethod.IsValid()) return (T)nullptr;
			return typedMethod(original);
		}
		/* @brief Helper overload: accept BNM::Class and convert to CompileTimeClass */
		template <typename T = void*> static T InstantiateGeneric(const BNM::Class &cls0, void* original) {
			return InstantiateGeneric<T>(cls0.GetCompileTimeClass(), original);
		}
		/* @brief Orig Type: T */
		/* @brief Helper: call generic Instantiate<T>() by providing compile-time class(es) */
		template <typename T = void*> static T Instantiate_1Generic(const BNM::CompileTimeClass &compileType0, void* original, BNM::Structures::Unity::Vector3 position, BNM::Structures::Unity::Quaternion rotation) {
			auto methodBase = StaticClass().GetMethod("Instantiate", 3);
			auto genericMethod = methodBase.GetGeneric({compileType0});
			if (!genericMethod.IsValid()) return (T)nullptr;
			BNM::Method<T> typedMethod = genericMethod;
			if (!typedMethod.IsValid()) return (T)nullptr;
			return typedMethod(original, position, rotation);
		}
		/* @brief Helper overload: accept BNM::Class and convert to CompileTimeClass */
		template <typename T = void*> static T Instantiate_1Generic(const BNM::Class &cls0, void* original, BNM::Structures::Unity::Vector3 position, BNM::Structures::Unity::Quaternion rotation) {
			return Instantiate_1Generic<T>(cls0.GetCompileTimeClass(), original, position, rotation);
		}
		/* @brief Orig Type: T */
		/* @brief Helper: call generic Instantiate<T>() by providing compile-time class(es) */
		template <typename T = void*> static T Instantiate_2Generic(const BNM::CompileTimeClass &compileType0, void* original, BNM::Structures::Unity::Vector3 position, BNM::Structures::Unity::Quaternion rotation, BNM::IL2CPP::Il2CppObject* parent) {
			auto methodBase = StaticClass().GetMethod("Instantiate", 4);
			auto genericMethod = methodBase.GetGeneric({compileType0});
			if (!genericMethod.IsValid()) return (T)nullptr;
			BNM::Method<T> typedMethod = genericMethod;
			if (!typedMethod.IsValid()) return (T)nullptr;
			return typedMethod(original, position, rotation, parent);
		}
		/* @brief Helper overload: accept BNM::Class and convert to CompileTimeClass */
		template <typename T = void*> static T Instantiate_2Generic(const BNM::Class &cls0, void* original, BNM::Structures::Unity::Vector3 position, BNM::Structures::Unity::Quaternion rotation, BNM::IL2CPP::Il2CppObject* parent) {
			return Instantiate_2Generic<T>(cls0.GetCompileTimeClass(), original, position, rotation, parent);
		}
		/* @brief Orig Type: T */
		/* @brief Helper: call generic Instantiate<T>() by providing compile-time class(es) */
		template <typename T = void*> static T Instantiate_3Generic(const BNM::CompileTimeClass &compileType0, void* original, BNM::IL2CPP::Il2CppObject* parent) {
			auto methodBase = StaticClass().GetMethod("Instantiate", 2);
			auto genericMethod = methodBase.GetGeneric({compileType0});
			if (!genericMethod.IsValid()) return (T)nullptr;
			BNM::Method<T> typedMethod = genericMethod;
			if (!typedMethod.IsValid()) return (T)nullptr;
			return typedMethod(original, parent);
		}
		/* @brief Helper overload: accept BNM::Class and convert to CompileTimeClass */
		template <typename T = void*> static T Instantiate_3Generic(const BNM::Class &cls0, void* original, BNM::IL2CPP::Il2CppObject* parent) {
			return Instantiate_3Generic<T>(cls0.GetCompileTimeClass(), original, parent);
		}
		/* @brief Orig Type: T */
		/* @brief Helper: call generic Instantiate<T>() by providing compile-time class(es) */
		template <typename T = void*> static T Instantiate_4Generic(const BNM::CompileTimeClass &compileType0, void* original, BNM::IL2CPP::Il2CppObject* parent, bool worldPositionStays) {
			auto methodBase = StaticClass().GetMethod("Instantiate", 3);
			auto genericMethod = methodBase.GetGeneric({compileType0});
			if (!genericMethod.IsValid()) return (T)nullptr;
			BNM::Method<T> typedMethod = genericMethod;
			if (!typedMethod.IsValid()) return (T)nullptr;
			return typedMethod(original, parent, worldPositionStays);
		}
		/* @brief Helper overload: accept BNM::Class and convert to CompileTimeClass */
		template <typename T = void*> static T Instantiate_4Generic(const BNM::Class &cls0, void* original, BNM::IL2CPP::Il2CppObject* parent, bool worldPositionStays) {
			return Instantiate_4Generic<T>(cls0.GetCompileTimeClass(), original, parent, worldPositionStays);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> static T Destroy(UnityEngine::Object* obj, float t) {
			static auto __bnm__method__ = (T(*)(UnityEngine::Object*, float))BNM::GetExternMethod("UnityEngine.Object::Destroy");
			return (T)__bnm__method__(obj, t);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> static T Destroy_1(UnityEngine::Object* obj) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Destroy", 1);
			return __bnm__method__(obj);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> static T DestroyImmediate(UnityEngine::Object* obj, bool allowDestroyingAssets) {
			static auto __bnm__method__ = (T(*)(UnityEngine::Object*, bool))BNM::GetExternMethod("UnityEngine.Object::DestroyImmediate");
			return (T)__bnm__method__(obj, allowDestroyingAssets);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> static T DestroyImmediate_1(UnityEngine::Object* obj) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("DestroyImmediate", 1);
			return __bnm__method__(obj);
		}
		/* @brief Orig Type: UnityEngine.Object[] */
		template <typename T = BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>*> static T FindObjectsOfType(BNM::MonoType* type) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("FindObjectsOfType", 1);
			return __bnm__method__(type);
		}
		/* @brief Orig Type: UnityEngine.Object[] */
		template <typename T = BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>*> static T FindObjectsOfType_1(BNM::MonoType* type, bool includeInactive) {
			static auto __bnm__method__ = (T(*)(BNM::MonoType*, bool))BNM::GetExternMethod("UnityEngine.Object::FindObjectsOfType");
			return (T)__bnm__method__(type, includeInactive);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> static T DontDestroyOnLoad(UnityEngine::Object* target) {
			static auto __bnm__method__ = (T(*)(UnityEngine::Object*))BNM::GetExternMethod("UnityEngine.Object::DontDestroyOnLoad");
			return (T)__bnm__method__(target);
		}
		/* @brief Orig Type: UnityEngine.HideFlags */
		template <typename T = int> T get_hideFlags() {
			static auto __bnm__method__ = (T(*)(BNM::IL2CPP::Il2CppObject*))BNM::GetExternMethod("UnityEngine.Object::get_hideFlags");
			return (T)__bnm__method__((BNM::IL2CPP::Il2CppObject*)this);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T set_hideFlags(int $value) {
			static auto __bnm__method__ = (T(*)(BNM::IL2CPP::Il2CppObject*, int))BNM::GetExternMethod("UnityEngine.Object::set_hideFlags");
			return (T)__bnm__method__((BNM::IL2CPP::Il2CppObject*)this, $value);
		}
		/* @brief Orig Type: T */
		/* @brief Helper: call generic FindObjectOfType<T>() by providing compile-time class(es) */
		template <typename T = void*> static T FindObjectOfTypeGeneric(const BNM::CompileTimeClass &compileType0) {
			auto methodBase = StaticClass().GetMethod("FindObjectOfType", 0);
			auto genericMethod = methodBase.GetGeneric({compileType0});
			if (!genericMethod.IsValid()) return (T)nullptr;
			BNM::Method<T> typedMethod = genericMethod;
			if (!typedMethod.IsValid()) return (T)nullptr;
			return typedMethod();
		}
		/* @brief Helper overload: accept BNM::Class and convert to CompileTimeClass */
		template <typename T = void*> static T FindObjectOfTypeGeneric(const BNM::Class &cls0) {
			return FindObjectOfTypeGeneric<T>(cls0.GetCompileTimeClass());
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> static T CheckNullArgument(BNM::IL2CPP::Il2CppObject* arg, BNM::Structures::Mono::String* message) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("CheckNullArgument", 2);
			return __bnm__method__(arg, message);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T FindObjectOfType(BNM::MonoType* type) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("FindObjectOfType", 1);
			return __bnm__method__(type);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T FindObjectOfType_1(BNM::MonoType* type, bool includeInactive) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("FindObjectOfType", 2);
			return __bnm__method__(type, includeInactive);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T ToString() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("ToString", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> static T op_Equality(UnityEngine::Object* x, UnityEngine::Object* y) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("op_Equality", 2);
			return __bnm__method__(x, y);
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> static T op_Inequality(UnityEngine::Object* x, UnityEngine::Object* y) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("op_Inequality", 2);
			return __bnm__method__(x, y);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> static T GetOffsetOfInstanceIDInCPlusPlusObject() {
			static auto __bnm__method__ = (T(*)())BNM::GetExternMethod("UnityEngine.Object::GetOffsetOfInstanceIDInCPlusPlusObject");
			return (T)__bnm__method__();
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T Internal_CloneSingle(UnityEngine::Object* data) {
			static auto __bnm__method__ = (T(*)(UnityEngine::Object*))BNM::GetExternMethod("UnityEngine.Object::Internal_CloneSingle");
			return (T)__bnm__method__(data);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T Internal_CloneSingleWithParent(UnityEngine::Object* data, BNM::IL2CPP::Il2CppObject* parent, bool worldPositionStays) {
			static auto __bnm__method__ = (T(*)(UnityEngine::Object*, BNM::IL2CPP::Il2CppObject*, bool))BNM::GetExternMethod("UnityEngine.Object::Internal_CloneSingleWithParent");
			return (T)__bnm__method__(data, parent, worldPositionStays);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T Internal_InstantiateSingle(UnityEngine::Object* data, BNM::Structures::Unity::Vector3 pos, BNM::Structures::Unity::Quaternion rot) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Internal_InstantiateSingle", 3);
			return __bnm__method__(data, pos, rot);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T Internal_InstantiateSingleWithParent(UnityEngine::Object* data, BNM::IL2CPP::Il2CppObject* parent, BNM::Structures::Unity::Vector3 pos, BNM::Structures::Unity::Quaternion rot) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Internal_InstantiateSingleWithParent", 4);
			return __bnm__method__(data, parent, pos, rot);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> static T ToString_1(UnityEngine::Object* obj) {
			static auto __bnm__method__ = (T(*)(UnityEngine::Object*))BNM::GetExternMethod("UnityEngine.Object::ToString");
			return (T)__bnm__method__(obj);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> static T GetName(UnityEngine::Object* obj) {
			static auto __bnm__method__ = (T(*)(UnityEngine::Object*))BNM::GetExternMethod("UnityEngine.Object::GetName");
			return (T)__bnm__method__(obj);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> static T SetName(UnityEngine::Object* obj, BNM::Structures::Mono::String* name) {
			static auto __bnm__method__ = (T(*)(UnityEngine::Object*, BNM::Structures::Mono::String*))BNM::GetExternMethod("UnityEngine.Object::SetName");
			return (T)__bnm__method__(obj, name);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T FindObjectFromInstanceID(int instanceID) {
			static auto __bnm__method__ = (T(*)(int))BNM::GetExternMethod("UnityEngine.Object::FindObjectFromInstanceID");
			return (T)__bnm__method__(instanceID);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T Internal_InstantiateSingle_Injected(UnityEngine::Object* data, BNM::IL2CPP::Il2CppObject* pos, BNM::IL2CPP::Il2CppObject* rot) {
			static auto __bnm__method__ = (T(*)(UnityEngine::Object*, BNM::IL2CPP::Il2CppObject*, BNM::IL2CPP::Il2CppObject*))BNM::GetExternMethod("UnityEngine.Object::Internal_InstantiateSingle_Injected");
			return (T)__bnm__method__(data, pos, rot);
		}
		/* @brief Orig Type: UnityEngine.Object */
		template <typename T = UnityEngine::Object*> static T Internal_InstantiateSingleWithParent_Injected(UnityEngine::Object* data, BNM::IL2CPP::Il2CppObject* parent, BNM::IL2CPP::Il2CppObject* pos, BNM::IL2CPP::Il2CppObject* rot) {
			static auto __bnm__method__ = (T(*)(UnityEngine::Object*, BNM::IL2CPP::Il2CppObject*, BNM::IL2CPP::Il2CppObject*, BNM::IL2CPP::Il2CppObject*))BNM::GetExternMethod("UnityEngine.Object::Internal_InstantiateSingleWithParent_Injected");
			return (T)__bnm__method__(data, parent, pos, rot);
		}
		
	};
}
