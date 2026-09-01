#pragma once
#include "BNM/BNMIncludes.hpp"

namespace GlobalNamespace {
	class SkillDirectory : public BNM::IL2CPP::Il2CppObject
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("", "SkillDirectory", BNM::Image("Assembly-CSharp.dll"));
		}
		
		/* @brief Orig Type: PerkContent[] */
		template <typename T = BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>*> T perk() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("perk");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: PerkContent[] */
		void set_perk(BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>* value) {
			static BNM::Field<BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>*> __bnm__field__ = StaticClass().GetField("perk");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: SkillContent[] */
		template <typename T = BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>*> T node() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("node");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: SkillContent[] */
		void set_node(BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>* value) {
			static BNM::Field<BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>*> __bnm__field__ = StaticClass().GetField("node");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> static T awakeningCost() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("awakeningCost");
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		static void set_awakeningCost(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("awakeningCost");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.Sprite */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T defaultFrame() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("defaultFrame");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.Sprite */
		void set_defaultFrame(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("defaultFrame");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.Sprite */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T awakeningFrame() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("awakeningFrame");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.Sprite */
		void set_awakeningFrame(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("awakeningFrame");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.Sprite */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T recallSprite() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("recallSprite");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.Sprite */
		void set_recallSprite(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("recallSprite");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnityEngine.Sprite */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T rerollSprite() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("rerollSprite");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnityEngine.Sprite */
		void set_rerollSprite(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("rerollSprite");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: WorldTreeDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T worldTree() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("worldTree");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: WorldTreeDirectory */
		void set_worldTree(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("worldTree");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: CyberhexDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T cyberHex() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("cyberHex");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: CyberhexDirectory */
		void set_cyberHex(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("cyberHex");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		
		/* @brief Orig Type: PerkContent */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T gdn(int a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("gdn", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: SkillContent */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T gdo(int a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("gdo", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: SkillContent */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T gdp(int a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("gdp", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: SkillAttribute */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T gdq(int a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("gdq", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T gdr() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("gdr", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T gds(int a) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("gds", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](a);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T gdt() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("gdt", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		
	};
}
