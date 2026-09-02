# Magisk/KernelSU Module Customization Script

ui_print "- Setting up configuration files..."

HOOK_PATH="/data/local/tmp/imgui_hooks.txt"

# Always place/update default hook config
ui_print "- Creating default hook configuration at $HOOK_PATH"
cp "$MODPATH/imgui_hooks.txt" "$HOOK_PATH"
chmod 666 "$HOOK_PATH"

# Ensure webroot permissions
if [ -d "$MODPATH/webroot" ]; then
    chmod -R 755 "$MODPATH/webroot"
fi

ui_print "- Installation complete!"
