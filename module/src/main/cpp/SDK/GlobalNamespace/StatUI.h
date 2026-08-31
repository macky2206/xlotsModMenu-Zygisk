#pragma once
#include "BNM/BNMIncludes.hpp"

namespace GlobalNamespace {
	class StatUI : public BNM::UnityEngine::MonoBehaviour
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("", "StatUI", BNM::Image("Assembly-CSharp.dll"));
		}
		
		/* @brief Orig Type: StatContent */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T content() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("content");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: StatContent */
		void set_content(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("content");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T tge() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("tge");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Double */
		void set_tge(double value) {
			static BNM::Field<double> __bnm__field__ = StaticClass().GetField("tge");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.GameObject */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T arrowGo() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("arrowGo");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.GameObject */
		void set_arrowGo(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("arrowGo");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: TMPro.TextMeshProUGUI */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T valueText() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("valueText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: TMPro.TextMeshProUGUI */
		void set_valueText(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("valueText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: TMPro.TextMeshProUGUI */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T nextValueText() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("nextValueText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: TMPro.TextMeshProUGUI */
		void set_nextValueText(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("nextValueText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.GameObject */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T levelGo() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("levelGo");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.GameObject */
		void set_levelGo(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("levelGo");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: TMPro.TextMeshProUGUI */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T levelText() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("levelText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: TMPro.TextMeshProUGUI */
		void set_levelText(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("levelText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: LerpComponent */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T levelLerp() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("levelLerp");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: LerpComponent */
		void set_levelLerp(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("levelLerp");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: TMPro.TextMeshProUGUI */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T descriptionText() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("descriptionText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: TMPro.TextMeshProUGUI */
		void set_descriptionText(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("descriptionText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: StatUpgradeButton */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T upgradeButton() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("upgradeButton");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: StatUpgradeButton */
		void set_upgradeButton(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("upgradeButton");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		
		/* @brief Orig Type: STAT */
		template <typename T = int> T kvf() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvf", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T TruncateLevelText(bool truncate) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("TruncateLevelText", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](truncate);
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> T kvg() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvg", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> T kvh() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvh", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Single */
		template <typename T = float> T kvi() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvi", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T kvj(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvj", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T kvk() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvk", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T kvl() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvl", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T kvm() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvm", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: xUpgradeCost */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T kvn(int a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvn", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: xUpgradeCost */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T kvo(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvo", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: xUpgradeCost */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T kvp(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvp", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T kvq() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvq", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T OnDescription() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("OnDescription", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T kvr(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvr", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T kvs(int a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvs", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T kvt(void* /*GENERICTYPE*/ a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvt", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T kvu(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvu", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T kvv(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kvv", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		
	};
}
