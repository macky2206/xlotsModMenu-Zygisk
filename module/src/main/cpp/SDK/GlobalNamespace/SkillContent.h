#pragma once
#include "BNM/BNMIncludes.hpp"

namespace GlobalNamespace {
	class SkillContent : public BNM::IL2CPP::Il2CppObject
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("", "SkillContent", BNM::Image("Assembly-CSharp.dll"));
		}
		
		/* @brief Orig Type: SkillAttribute */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T $value() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("value");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: SkillAttribute */
		void set_$value(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("value");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T sortID() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("sortID");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		void set_sortID(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("sortID");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.Sprite */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T icon() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("icon");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.Sprite */
		void set_icon(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("icon");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T skillName() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("skillName");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.String */
		void set_skillName(BNM::Structures::Mono::String* value) {
			static BNM::Field<BNM::Structures::Mono::String*> __bnm__field__ = StaticClass().GetField("skillName");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T skillDesc() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("skillDesc");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.String */
		void set_skillDesc(BNM::Structures::Mono::String* value) {
			static BNM::Field<BNM::Structures::Mono::String*> __bnm__field__ = StaticClass().GetField("skillDesc");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T levelCap() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("levelCap");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		void set_levelCap(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("levelCap");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T awakenedCap() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("awakenedCap");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		void set_awakenedCap(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("awakenedCap");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: CostAttribute */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T cost() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("cost");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: CostAttribute */
		void set_cost(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("cost");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		
		/* @brief Orig Type: SKILL */
		template <typename T = int> T mlm() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("mlm", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> T mln() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("mln", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T mlo() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("mlo", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T mlp(bool a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("mlp", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> T mlq() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("mlq", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T mlr() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("mlr", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		
	};
}
