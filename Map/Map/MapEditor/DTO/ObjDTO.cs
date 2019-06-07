using Map.MapEditor.Object;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.DTO
{
    public class ObjDTO
    {
        private ObjGame obj;
        private String imagePath;

        #region
        public ObjGame Obj
        {
            get
            {
                return obj;
            }

            set
            {
                obj = value;
            }
        }

        public string ImagePath
        {
            get
            {
                return imagePath;
            }

            set
            {
                imagePath = value;
            }
        }
        #endregion

        public ObjDTO(ObjGame objGame, String imagePath)
        {
            this.Obj = objGame;
            this.ImagePath = imagePath;
        }


    }
}
