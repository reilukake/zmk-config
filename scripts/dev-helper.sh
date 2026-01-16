#!/bin/bash

# ZMK Sofle Development Helper Script
# This script helps with common development tasks for your ZMK configuration

set -e

echo "🔧 ZMK Sofle Development Helper"
echo "================================"

case "$1" in
    "edit-keymap")
        echo "📝 Opening keymap for editing..."
        ${EDITOR:-nvim} config/sofle.keymap
        ;;
    "edit-config")
        echo "⚙️ Opening configuration for editing..."
        ${EDITOR:-nvim} config/sofle.conf
        ;;
    "status")
        echo "📊 Repository Status:"
        git status
        echo ""
        echo "🔗 Remote URL:"
        git remote get-url origin
        echo ""
        echo "🌿 Current Branch:"
        git branch --show-current
        ;;
    "push")
        echo "🚀 Pushing changes to trigger build..."
        git add .
        echo "💬 Enter commit message:"
        read -r commit_msg
        git commit -m "$commit_msg"
        git push origin main
        echo ""
        echo "✅ Changes pushed! Check GitHub Actions for build status:"
        echo "   https://github.com/solotitan/zmk-sofle-wireless-config/actions"
        ;;
    "pull")
        echo "⬇️ Pulling latest changes..."
        git pull origin main
        ;;
    "backup")
        echo "💾 Creating backup branch..."
        timestamp=$(date +"%Y%m%d_%H%M%S")
        backup_branch="backup_$timestamp"
        git checkout -b "$backup_branch"
        git push origin "$backup_branch"
        git checkout main
        echo "✅ Backup created: $backup_branch"
        ;;
    "help"|*)
        echo "Usage: $0 <command>"
        echo ""
        echo "Available commands:"
        echo "  edit-keymap  - Edit the keymap file"
        echo "  edit-config  - Edit the configuration file"
        echo "  status       - Show repository status"
        echo "  push         - Add, commit, and push changes"
        echo "  pull         - Pull latest changes"
        echo "  backup       - Create a backup branch"
        echo "  help         - Show this help message"
        echo ""
        echo "📖 Key files:"
        echo "  config/sofle.keymap - Your key mappings"
        echo "  config/sofle.conf   - Hardware configuration"
        echo "  build.yaml          - Build configuration"
        echo ""
        echo "🔗 Useful links:"
        echo "  GitHub Actions: https://github.com/solotitan/zmk-sofle-wireless-config/actions"
        echo "  ZMK Docs: https://zmk.dev/docs"
        echo "  Keymap Reference: docs/keymap-reference.md"
        ;;
esac