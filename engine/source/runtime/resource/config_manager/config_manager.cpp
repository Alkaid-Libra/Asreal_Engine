#include "runtime/resource/config_manager/config_manager.h"

#include <fstream>
#include <string>

namespace VE
{
    void ConfigManager::initialize(const EngineInitParams& init_param)
    {
        m_root_folder = init_param.m_root_folder;

        // read configs
        std::ifstream config_file(init_param.m_config_file_path);
        std::string config_line;
        while (std::getline(config_file, config_line))
        {
            size_t seperate_pos = config_line.find_first_of('=');
            if (seperate_pos > 0 && seperate_pos < (config_line.length() - 1))
            {
                std::string name = config_line.substr(0, seperate_pos);
                std::string value = config_line.substr(seperate_pos + 1, config_line.length() - seperate_pos - 1);
                if (name.compare("AssetFolder") == 0)
                {
                    m_asset_folder = m_root_folder / value;
                }
                else if (name.compare("SchemaFolder") == 0)
                {
                    m_schema_folder = m_root_folder / value;
                }                
                else if (name.compare("DefaultWorld") == 0)
                {
                    m_default_world_path = m_asset_folder / value;
                }                
                else if (name.compare("BigIconFile") == 0)
                {
                    m_editor_big_icon_path = m_root_folder / value;
                }                
                else if (name.compare("SmallIconFile") == 0)
                {
                    m_editor_small_icon_path = m_root_folder / value;
                }                
                else if (name.compare("FontFile") == 0)
                {
                    m_editor_font_path = m_root_folder / value;
                }                
            }
        }
    }
} // namespace VE
