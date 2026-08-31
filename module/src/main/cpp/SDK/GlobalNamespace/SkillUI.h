#pragma once
#include "BNM/BNMIncludes.hpp"

namespace GlobalNamespace {
	class SkillUI : public BNM::UnityEngine::MonoBehaviour
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("", "SkillUI", BNM::Image("Assembly-CSharp.dll"));
		}
		
		/* @brief Orig Type: UnityEngine.UI.Image */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T awakenedBg() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("awakenedBg");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.UI.Image */
		void set_awakenedBg(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("awakenedBg");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.Vector3 */
		template <typename T = BNM::Structures::Unity::Vector3> T awakeningLevelOffset() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("awakeningLevelOffset");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.Vector3 */
		void set_awakeningLevelOffset(BNM::Structures::Unity::Vector3 value) {
			static BNM::Field<BNM::Structures::Unity::Vector3> __bnm__field__ = StaticClass().GetField("awakeningLevelOffset");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.UI.Image */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T iconImage() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("iconImage");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.UI.Image */
		void set_iconImage(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("iconImage");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.UI.Image */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T frameImage() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("frameImage");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.UI.Image */
		void set_frameImage(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("frameImage");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: TMPro.TextMeshProUGUI */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T titleText() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("titleText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: TMPro.TextMeshProUGUI */
		void set_titleText(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("titleText");
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
		/* @brief Orig Type: TMPro.TextMeshProUGUI */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T descText() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("descText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: TMPro.TextMeshProUGUI */
		void set_descText(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("descText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.GameObject */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T elixirGo() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("elixirGo");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.GameObject */
		void set_elixirGo(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("elixirGo");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.GameObject */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T maxGo() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("maxGo");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.GameObject */
		void set_maxGo(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("maxGo");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: TMPro.TextMeshProUGUI */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T costText() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("costText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: TMPro.TextMeshProUGUI */
		void set_costText(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("costText");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.UI.Button */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T rerollButton() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("rerollButton");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.UI.Button */
		void set_rerollButton(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("rerollButton");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.UI.Button */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T upgradeButton() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("upgradeButton");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.UI.Button */
		void set_upgradeButton(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("upgradeButton");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: SkillContent */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T content() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("content");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: SkillContent */
		void set_content(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("content");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: SkillData */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T tdp() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("tdp");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: SkillData */
		void set_tdp(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("tdp");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UpgradeMode */
		template <typename T = int> T tdq() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("tdq");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UpgradeMode */
		void set_tdq(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("tdq");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: xUpgradeCost */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T tdr() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("tdr");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: xUpgradeCost */
		void set_tdr(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("tdr");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		
		/* @brief Orig Type: SKILL */
		template <typename T = int> T kpf() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kpf", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T kpg() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kpg", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T kph() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kph", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T kpi(double a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kpi", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T kpj() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kpj", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T kpk() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kpk", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: xUpgradeCost */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T kpw(int a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kpw", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Boolean */
		template <typename T = bool> T kpx() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kpx", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T SetUpgradeMode(int upgradeMode) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("SetUpgradeMode", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](upgradeMode);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T kpy() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kpy", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T kpz() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kpz", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T kqa() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kqa", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.String */
		template <typename T = BNM::Structures::Mono::String*> T kqb(bool a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("kqb", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T Upgrade() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Upgrade", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Void */
		template <typename T = void> T Reroll() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Reroll", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		
	};
}
