#pragma once
#include "BNM/BNMIncludes.hpp"

namespace GlobalNamespace {
	class PlayerAttributeValue : public BNM::IL2CPP::Il2CppObject
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("", "PlayerAttributeValue", BNM::Image("Assembly-CSharp.dll"));
		}
		
		/* @brief Orig Type: STAT */
		template <typename T = int> T id() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("id");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: STAT */
		void set_id(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("id");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T baseValue() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("baseValue");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Double */
		void set_baseValue(double value) {
			static BNM::Field<double> __bnm__field__ = StaticClass().GetField("baseValue");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T valueIncrement() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("valueIncrement");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Double */
		void set_valueIncrement(double value) {
			static BNM::Field<double> __bnm__field__ = StaticClass().GetField("valueIncrement");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T valueExponentialIncrement() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("valueExponentialIncrement");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Double */
		void set_valueExponentialIncrement(double value) {
			static BNM::Field<double> __bnm__field__ = StaticClass().GetField("valueExponentialIncrement");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T logMultiplier() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("logMultiplier");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		void set_logMultiplier(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("logMultiplier");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T logStart() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("logStart");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		void set_logStart(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("logStart");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T valueFormat() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("valueFormat");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.String */
		void set_valueFormat(BNM::Structures::Mono::String* value) {
			static BNM::Field<BNM::Structures::Mono::String*> __bnm__field__ = StaticClass().GetField("valueFormat");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T valueUnit() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("valueUnit");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.String */
		void set_valueUnit(BNM::Structures::Mono::String* value) {
			static BNM::Field<BNM::Structures::Mono::String*> __bnm__field__ = StaticClass().GetField("valueUnit");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		
		/* @brief Orig Type: System.Double */
		template <typename T = double> T iqh(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqh", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T iqi(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqi", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T iqj(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqj", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T iqk(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqk", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T iql(BNM::IL2CPP::Il2CppObject* a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iql", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		
	};
}
