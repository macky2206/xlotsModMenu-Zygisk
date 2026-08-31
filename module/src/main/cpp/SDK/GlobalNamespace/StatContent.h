#pragma once
#include "BNM/BNMIncludes.hpp"

namespace GlobalNamespace {
	class StatContent : public BNM::IL2CPP::Il2CppObject
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("", "StatContent", BNM::Image("Assembly-CSharp.dll"));
		}
		
		/* @brief Orig Type: PlayerAttributeValue */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T $value() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("value");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: PlayerAttributeValue */
		void set_$value(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("value");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T statName() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("statName");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.String */
		void set_statName(BNM::Structures::Mono::String* value) {
			static BNM::Field<BNM::Structures::Mono::String*> __bnm__field__ = StaticClass().GetField("statName");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.Sprite */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T statImage() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("statImage");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.Sprite */
		void set_statImage(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("statImage");
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
		/* @brief Orig Type: System.Double */
		template <typename T = double> T cap() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("cap");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Double */
		void set_cap(double value) {
			static BNM::Field<double> __bnm__field__ = StaticClass().GetField("cap");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T dayUnlock() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("dayUnlock");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		void set_dayUnlock(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("dayUnlock");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T desc() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("desc");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.String */
		void set_desc(BNM::Structures::Mono::String* value) {
			static BNM::Field<BNM::Structures::Mono::String*> __bnm__field__ = StaticClass().GetField("desc");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		
		/* @brief Orig Type: System.Double */
		template <typename T = double> T nak() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("nak", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T nai(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("nai", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T nal(BNM::IL2CPP::Il2CppObject* a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("nal", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T naj(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("naj", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T nam(BNM::IL2CPP::Il2CppObject* a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("nam", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		
	};
}
