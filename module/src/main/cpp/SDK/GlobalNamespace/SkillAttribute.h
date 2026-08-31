#pragma once
#include "BNM/BNMIncludes.hpp"

namespace GlobalNamespace {
	class SkillAttribute : public BNM::IL2CPP::Il2CppObject
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("", "SkillAttribute", BNM::Image("Assembly-CSharp.dll"));
		}
		
		/* @brief Orig Type: SKILL */
		template <typename T = int> T id() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("id");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: SKILL */
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
		template <typename T = double> T awakenIncrement() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("awakenIncrement");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Double */
		void set_awakenIncrement(double value) {
			static BNM::Field<double> __bnm__field__ = StaticClass().GetField("awakenIncrement");
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
		template <typename T = BNM::Structures::Mono::String*> T valueOperator() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("valueOperator");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.String */
		void set_valueOperator(BNM::Structures::Mono::String* value) {
			static BNM::Field<BNM::Structures::Mono::String*> __bnm__field__ = StaticClass().GetField("valueOperator");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T valueText() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("valueText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.String */
		void set_valueText(BNM::Structures::Mono::String* value) {
			static BNM::Field<BNM::Structures::Mono::String*> __bnm__field__ = StaticClass().GetField("valueText");
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
		
		/* @brief Orig Type: System.Double */
		template <typename T = double> T iqu(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqu", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> static T iqv(double a, double b) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqv", 2);
			return __bnm__method__(a, b);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T iqw(double a, double b) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqw", 2);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a, b);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T iqx(double a, double b) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqx", 2);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a, b);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T iqy(double a, double b) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqy", 2);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a, b);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T iqz(double a, bool b, double c) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqz", 3);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a, b, c);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T ira(double a, bool b, double c) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("ira", 3);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a, b, c);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T irb(double a, bool b, double c) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("irb", 3);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a, b, c);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T irc(bool a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("irc", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T ird(double a, bool b, double c) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("ird", 3);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a, b, c);
		}
		
	};
}
