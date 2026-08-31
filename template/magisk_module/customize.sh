# Magisk/KernelSU Module Customization Script

# Set up default configuration if it doesn't exist
ui_print "- Checking for existing configuration..."

BACKUP_PATH="/data/local/tmp/imgui_config.txt"

if [ ! -f "$BACKUP_PATH" ]; then
    ui_print "- Creating default configuration at $BACKUP_PATH"
    cp "$MODPATH/config.txt" "$BACKUP_PATH"
    chmod 666 "$BACKUP_PATH"
else
    ui_print "- Existing configuration found, preserving settings."
fi

# Ensure webroot permissions (for KernelSU)
if [ -d "$MODPATH/webroot" ]; then
    chmod -R 755 "$MODPATH/webroot"
fi

ui_print "- Installation complete!"
