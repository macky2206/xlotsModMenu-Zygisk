#pragma once
#include "BNM/BNMIncludes.hpp"

namespace GlobalNamespace {
	class CostAttribute : public BNM::IL2CPP::Il2CppObject
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("", "CostAttribute", BNM::Image("Assembly-CSharp.dll"));
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
		template <typename T = double> T iqo(int64_t a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqo", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T iqp(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("iqp", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		
	};
}
