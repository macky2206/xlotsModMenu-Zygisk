#pragma once
#include "BNM/BNMIncludes.hpp"

namespace GlobalNamespace {
	class GameDirectory : public BNM::UnityEngine::MonoBehaviour
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("", "GameDirectory", BNM::Image("Assembly-CSharp.dll"));
		}
		
		/* @brief Orig Type: StatDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T statDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("statDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: StatDirectory */
		void set_statDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("statDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: SpellDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T spellDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("spellDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: SpellDirectory */
		void set_spellDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("spellDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: WeaponDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T weaponDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("weaponDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: WeaponDirectory */
		void set_weaponDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("weaponDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: RuneDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T runeDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("runeDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: RuneDirectory */
		void set_runeDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("runeDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: CatalystDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T catalystDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("catalystDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: CatalystDirectory */
		void set_catalystDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("catalystDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: HeroDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T heroDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("heroDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: HeroDirectory */
		void set_heroDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("heroDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: SkillDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T skillDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("skillDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: SkillDirectory */
		void set_skillDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("skillDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: WallDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T wallDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("wallDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: WallDirectory */
		void set_wallDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("wallDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnlockDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T unlockDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("unlockDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: UnlockDirectory */
		void set_unlockDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("unlockDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: ResourceDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T resourceDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("resourceDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: ResourceDirectory */
		void set_resourceDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("resourceDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: EquipmentDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T equipmentDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("equipmentDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: EquipmentDirectory */
		void set_equipmentDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("equipmentDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: SpriteDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T spriteDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("spriteDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: SpriteDirectory */
		void set_spriteDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("spriteDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: AchievementDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T achievementDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("achievementDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: AchievementDirectory */
		void set_achievementDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("achievementDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: GuildDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T guildDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("guildDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: GuildDirectory */
		void set_guildDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("guildDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: PetDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> T petDirectory() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("petDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: PetDirectory */
		void set_petDirectory(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("petDirectory");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: GameDirectory */
		template <typename T = GlobalNamespace::GameDirectory*> static T qud() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("qud");
			return __bnm__field__();
		}
		/* @param value Orig Type: GameDirectory */
		static void set_qud(GlobalNamespace::GameDirectory* value) {
			static BNM::Field<GlobalNamespace::GameDirectory*> __bnm__field__ = StaticClass().GetField("qud");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: StatDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T stat() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("stat");
			return __bnm__field__();
		}
		/* @param value Orig Type: StatDirectory */
		static void set_stat(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("stat");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: SpellDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T spell() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("spell");
			return __bnm__field__();
		}
		/* @param value Orig Type: SpellDirectory */
		static void set_spell(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("spell");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: WeaponDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T weapon() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("weapon");
			return __bnm__field__();
		}
		/* @param value Orig Type: WeaponDirectory */
		static void set_weapon(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("weapon");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: RuneDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T rune() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("rune");
			return __bnm__field__();
		}
		/* @param value Orig Type: RuneDirectory */
		static void set_rune(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("rune");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: CatalystDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T catalyst() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("catalyst");
			return __bnm__field__();
		}
		/* @param value Orig Type: CatalystDirectory */
		static void set_catalyst(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("catalyst");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: HeroDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T hero() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("hero");
			return __bnm__field__();
		}
		/* @param value Orig Type: HeroDirectory */
		static void set_hero(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("hero");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: SkillDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T skill() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("skill");
			return __bnm__field__();
		}
		/* @param value Orig Type: SkillDirectory */
		static void set_skill(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("skill");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: WallDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T wall() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("wall");
			return __bnm__field__();
		}
		/* @param value Orig Type: WallDirectory */
		static void set_wall(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("wall");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: UnlockDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T unlock() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("unlock");
			return __bnm__field__();
		}
		/* @param value Orig Type: UnlockDirectory */
		static void set_unlock(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("unlock");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: ResourceDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T resource() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("resource");
			return __bnm__field__();
		}
		/* @param value Orig Type: ResourceDirectory */
		static void set_resource(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("resource");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: EquipmentDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T equipment() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("equipment");
			return __bnm__field__();
		}
		/* @param value Orig Type: EquipmentDirectory */
		static void set_equipment(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("equipment");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: SpriteDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T sprite() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("sprite");
			return __bnm__field__();
		}
		/* @param value Orig Type: SpriteDirectory */
		static void set_sprite(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("sprite");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: AchievementDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T achievement() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("achievement");
			return __bnm__field__();
		}
		/* @param value Orig Type: AchievementDirectory */
		static void set_achievement(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("achievement");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: GuildDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T guild() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("guild");
			return __bnm__field__();
		}
		/* @param value Orig Type: GuildDirectory */
		static void set_guild(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("guild");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: PetDirectory */
		template <typename T = BNM::IL2CPP::Il2CppObject*> static T pet() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("pet");
			return __bnm__field__();
		}
		/* @param value Orig Type: PetDirectory */
		static void set_pet(BNM::IL2CPP::Il2CppObject* value) {
			static BNM::Field<BNM::IL2CPP::Il2CppObject*> __bnm__field__ = StaticClass().GetField("pet");
			__bnm__field__.Set(value);
		}
		
		/* @brief Orig Type: System.Void */
		template <typename T = void> T Awake() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Awake", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		
	};
}
