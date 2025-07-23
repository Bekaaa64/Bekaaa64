import os
from .. import loader

@loader.tds
class VoiceSoundsMod(loader.Module):
    """Модуль для отправки голосовых по командам типа .смех, .оска, .мем."""
    strings = {"name": "voice_sounds"}
    sounds = {
        "смех": "sounds/smex.ogg",
        "оска": "sounds/oska.ogg",
        "мем": "sounds/mem2.ogg",
    }

    async def client_ready(self, client, db):
        self.client = client

    async def watcher(self, message):
        if not message.out or not message.text.startswith("."):
            return

        cmd = message.text[1:].lower().strip()
        if cmd in self.sounds:
            path = os.path.join(os.path.dirname(__file__), self.sounds[cmd])
            if os.path.exists(path):
                await self.client.send_file(
                    message.chat_id,
                    path,
                    voice_note=True,
                    reply_to=message.id
                )
            else:
                await message.respond(f"Звук {{cmd}} не найден.")
              
